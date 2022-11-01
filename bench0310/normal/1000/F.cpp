#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=500005;
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

int query(int idx,int l,int r,int ql,int qr,int lim)
{
    if(ql>qr) return 0;
    if(tree[idx]<=lim) return 0;
    if(l==r) return l;
    int m=(l+r)/2;
    int res=query(2*idx,l,m,ql,min(qr,m),lim);
    if(res!=0) return res;
    return query(2*idx+1,m+1,r,max(ql,m+1),qr,lim);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n+1,0);
    vector<int> v[N];
    for(int i=1;i<N;i++) v[i].push_back(0);
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        v[a[i]].push_back(i);
    }
    for(int i=1;i<N;i++) v[i].push_back(n+1);
    vector<int> one(n+1,0);
    vector<int> two(n+1,n+1);
    for(int i=1;i<N;i++)
    {
        for(int j=1;j<(int)v[i].size()-1;j++)
        {
            one[v[i][j]]=v[i][j-1];
            two[v[i][j]]=v[i][j+1];
        }
    }
    vector<array<int,3>> e; //l,r,id
    for(int i=1;i<=n;i++) e.push_back({one[i],two[i],i});
    sort(e.begin(),e.end());
    int q;
    cin >> q;
    vector<array<int,3>> queries(q); //l,r,id
    for(int i=1;i<=q;i++)
    {
        int l,r;
        cin >> l >> r;
        queries[i-1]={l,r,i};
    }
    sort(queries.begin(),queries.end());
    int idx=0;
    vector<int> res(q+1,0);
    for(auto [l,r,id]:queries)
    {
        while(idx<n&&e[idx][0]<l)
        {
            update(1,1,n,e[idx][2],e[idx][1]);
            idx++;
        }
        res[id]=a[query(1,1,n,l,r,r)];
    }
    for(int i=1;i<=q;i++) cout << res[i] << "\n";
    return 0;
}