#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=200005;
int n;
vector<int> tree(4*N,0);

void update(int idx,int l,int r,int pos,int val)
{
    if(l==r) tree[idx]=val;
    else
    {
        int m=(l+r)/2;
        if(pos<=m) update(2*idx,l,m,pos,val);
        else update(2*idx+1,m+1,r,pos,val);
        tree[idx]=tree[2*idx]+tree[2*idx+1];
    }
}

int query(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return 0;
    if(l==ql&&r==qr) return tree[idx];
    int m=(l+r)/2;
    return query(2*idx,l,m,ql,min(qr,m))+query(2*idx+1,m+1,r,max(ql,m+1),qr);
}

int get_pos(int x)
{
    return query(1,1,n,1,x);
}

int descend(int idx,int l,int r,int ql,int qr,int tp)
{
    if(ql>qr) return N;
    if(tree[idx]==0) return N;
    if(l==r) return l;
    int m=(l+r)/2;
    if(tp==0)
    {
        int x=descend(2*idx+1,m+1,r,max(ql,m+1),qr,tp);
        if(x!=N) return x;
        else return descend(2*idx,l,m,ql,min(qr,m),tp);
    }
    else
    {
        int x=descend(2*idx,l,m,ql,min(qr,m),tp);
        if(x!=N) return x;
        else return descend(2*idx+1,m+1,r,max(ql,m+1),qr,tp);
    }
}

int get_prv(int x)
{
    return descend(1,1,n,1,x,0);
}

int get_nxt(int x)
{
    return descend(1,1,n,x,n,1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        n=s.size();
        s="$"+s;
        int eq=0;
        set<int> e[26];
        auto get_mx=[&]()->array<int,2>
        {
            array<int,2> mx={-1,0};
            for(int i=0;i<26;i++) mx=max(mx,{(int)e[i].size(),i});
            return mx;
        };
        for(int i=1;i<n;i++)
        {
            if(s[i]==s[i+1])
            {
                eq++;
                e[s[i]-'a'].insert(i);
            }
        }
        auto get_diff=[&]()->array<int,2>
        {
            array<int,2> one={n+1,-1};
            for(int i=0;i<26;i++) if(e[i].size()>0) one=min(one,{*e[i].begin(),i});
            array<int,2> two={n+1,-1};
            for(int i=0;i<26;i++)
            {
                if(e[i].empty()||i==one[1]) continue;
                auto it=e[i].lower_bound(one[0]);
                if(it!=e[i].end()) two=min(two,{*it,i});
            }
            auto it=e[one[1]].lower_bound(two[0]);
            it--;
            one[0]=(*it);
            return {get_nxt(one[0]+1),two[0]};
        };
        cout << 1+max((eq+1)/2,get_mx()[0]) << "\n";
        for(int i=1;i<=n;i++) update(1,1,n,i,1);
        while(get_pos(n)>0)
        {
            auto [ecnt,c]=get_mx();
            if((eq+1)/2>ecnt)
            {
                auto [l,r]=get_diff();
                int one=(s[l]-'a');
                int two=(s[r]-'a');
                cout << get_pos(l) << " " << get_pos(r) << "\n";
                eq-=2;
                e[one].erase(get_prv(l-1));
                e[two].erase(r);
                for(int i=l;i<=r;i=get_nxt(i)) update(1,1,n,i,0);
            }
            else if(eq>0&&eq!=ecnt)
            {
                int one=(*e[c].begin());
                array<int,2> two={n+1,-1};
                for(int i=0;i<26;i++)
                {
                    if(e[i].empty()||i==c) continue;
                    auto it=e[i].lower_bound(one);
                    if(it!=e[i].end()) two=min(two,{*it,i});
                }
                if(two[1]!=-1)
                {
                    auto it=e[c].lower_bound(two[0]);
                    it--;
                    cout << get_pos(get_nxt((*it)+1)) << " " << get_pos(two[0]) << "\n";
                    eq-=2;
                    e[c].erase(it);
                    e[two[1]].erase(two[0]);
                    for(int i=get_nxt((*it)+1);i<=two[0];i=get_nxt(i)) update(1,1,n,i,0);
                    continue;
                }
                two={0,-1};
                for(int i=0;i<26;i++)
                {
                    if(e[i].empty()||i==c) continue;
                    auto it=e[i].lower_bound(one);
                    if(it==e[i].begin()) continue;
                    it--;
                    two=max(two,{*it,i});
                }
                cout << get_pos(get_nxt(two[0]+1)) << " " << get_pos(one) << "\n";
                eq-=2;
                e[two[1]].erase(two[0]);
                e[c].erase(one);
                for(int i=get_nxt(two[0]+1);i<=one;i=get_nxt(i)) update(1,1,n,i,0);
            }
            else if(eq==ecnt)
            {
                int now=1;
                e[c].insert(n);
                for(int nxt:e[c])
                {
                    cout << get_pos(now) << " " << get_pos(nxt) << "\n";
                    for(int i=now;i<=nxt;i=get_nxt(i)) update(1,1,n,i,0);
                    now=get_nxt(nxt);
                }
            }
            else
            {
                cout << 1 << " " << get_pos(n) << "\n";
                while(get_pos(n)>0) update(1,1,n,get_nxt(1),0);
            }
        }
    }
    return 0;
}