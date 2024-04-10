#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;

int get_prv(set<int> &s,int idx)
{
    auto it=s.lower_bound(idx);
    if(it==s.begin()) return 0;
    else return (*prev(it));
}

int get_nxt(set<int> &s,int idx)
{
    auto it=s.lower_bound(idx);
    if(it==s.end()) return 0;
    else return (*it);
}

const int N=200005;
vector<int> tree(4*N,0);

void update(int idx,int l,int r,int pos,int val)
{
    if(l==r) tree[idx]=val;
    else
    {
        int m=(l+r)/2;
        if(pos<=m) update(2*idx,l,m,pos,val);
        else update(2*idx+1,m+1,r,pos,val);
        tree[idx]=max(tree[2*idx],tree[2*idx+1]);
    }
}

int query(int idx,int l,int r,int ql,int qr,int i)
{
    if(ql>qr) return 0;
    if(tree[idx]<i) return 0;
    if(l==r) return l;
    int m=(l+r)/2;
    int one=query(2*idx,l,m,ql,min(qr,m),i);
    if(one!=0) return one;
    return query(2*idx+1,m+1,r,max(ql,m+1),qr,i);
}

array<vector<array<int,6>>,2> solve(vector<int> a)
{
    //get up/down
    vector<int> upleft(n+1,0);
    vector<int> upright(n+1,0);
    vector<int> downright(n+1,0);
    set<int> s;
    vector<array<int,2>> tmp(n);
    for(int i=1;i<=n;i++) tmp[i-1]={a[i],i};
    sort(tmp.begin(),tmp.end(),greater<array<int,2>>());
    int l=0;
    while(l<n)
    {
        int r=l;
        while(r+1<n&&tmp[r+1][0]==tmp[l][0]) r++;
        for(int i=l;i<=r;i++)
        {
            int idx=tmp[i][1];
            upleft[idx]=get_prv(s,idx);
            upright[idx]=get_nxt(s,idx);
        }
        for(int i=l;i<=r;i++) s.insert(tmp[i][1]);
        l=r+1;
    }
    reverse(tmp.begin(),tmp.end());
    s.clear();
    l=0;
    while(l<n)
    {
        int r=l;
        while(r+1<n&&tmp[r+1][0]==tmp[l][0]) r++;
        for(int i=l;i<=r;i++)
        {
            int idx=tmp[i][1];
            downright[idx]=get_nxt(s,idx);
        }
        for(int i=l;i<=r;i++) s.insert(tmp[i][1]);
        l=r+1;
    }
    //get threes
    vector<array<int,6>> three;
    for(int i=1;i<=n;i++)
    {
        if(upleft[i]!=0&&upright[i]!=0) three.push_back({upleft[i],upright[i],upleft[i],i,upright[i],0});
    }
    //get fours
    vector<array<int,6>> four;
    reverse(tmp.begin(),tmp.end());
    for(int o=0;o<n;o++)
    {
        int i=tmp[o][1];
        int lim=downright[i];
        if(lim!=0)
        {
            int r=query(1,1,n,lim,n,i);
            l=upleft[r];
            if(r!=0) four.push_back({i,r,i,min(l,lim),max(l,lim),r});
        }
        update(1,1,n,i,upleft[i]);
    }
    for(int i=1;i<=n;i++) update(1,1,n,i,0);
    return {three,four};
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> n >> q;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++) cin >> a[i];
    array<int,6> bad={0,n+1,0,0,0,0}; //l,r,a,b,c,d
    vector<array<int,6>> three(n+1,bad);
    vector<array<int,6>> four(n+1,bad);
    auto [three1,four1]=solve(a);
    for(auto t:three1) if(t[1]<three[t[0]][1]) three[t[0]]=t;
    for(auto t:four1) if(t[1]<four[t[0]][1]) four[t[0]]=t;
    for(int i=1;i<=n;i++) a[i]=(1<<30)-a[i];
    auto [three2,four2]=solve(a);
    for(auto t:three2) if(t[1]<three[t[0]][1]) three[t[0]]=t;
    for(auto t:four2) if(t[1]<four[t[0]][1]) four[t[0]]=t;
    array<int,6> t=bad;
    array<int,6> f=bad;
    vector<array<int,2>> queries[n+1]; //r,id
    for(int i=1;i<=q;i++)
    {
        int l,r;
        cin >> l >> r;
        queries[l].push_back({r,i});
    }
    vector<int> res[q+1];
    for(int i=n;i>=1;i--)
    {
        if(three[i][1]<t[1]) t=three[i];
        if(four[i][1]<f[1]) f=four[i];
        for(auto [r,id]:queries[i])
        {
            if(f[1]<=r) res[id]={f[2],f[3],f[4],f[5]};
            else if(t[1]<=r) res[id]={t[2],t[3],t[4]};
        }
    }
    for(int i=1;i<=q;i++)
    {
        cout << res[i].size() << "\n";
        for(int x:res[i]) cout << x << " ";
        cout << "\n";
    }
    return 0;
}