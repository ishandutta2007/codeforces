#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=400005;
int n;
vector<int> tree(4*N,0);
vector<int> lazy(4*N,0);

void pull(int idx)
{
    tree[idx]=max(tree[2*idx],tree[2*idx+1]);
}

void apply(int idx,int x)
{
    tree[idx]+=x;
    lazy[idx]+=x;
}

void push(int idx)
{
    for(int i=0;i<2;i++) apply(2*idx+i,lazy[idx]);
    lazy[idx]=0;
}

void build(int idx,int l,int r)
{
    if(l==r) tree[idx]=-(n+1-l);
    else
    {
        int m=(l+r)/2;
        build(2*idx,l,m);
        build(2*idx+1,m+1,r);
        pull(idx);
    }
}

void update(int idx,int l,int r,int ql,int qr,int x)
{
    if(ql>qr) return;
    if(l==ql&&r==qr) apply(idx,x);
    else
    {
        int m=(l+r)/2;
        push(idx);
        update(2*idx,l,m,ql,min(qr,m),x);
        update(2*idx+1,m+1,r,max(ql,m+1),qr,x);
        pull(idx);
    }
}

int query(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return 0;
    if(l==ql&&r==qr) return tree[idx];
    int m=(l+r)/2;
    push(idx);
    return max(query(2*idx,l,m,ql,min(qr,m)),query(2*idx+1,m+1,r,max(ql,m+1),qr));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k,m;
    cin >> n >> k >> m;
    build(1,1,2*n-1);
    vector<int> cnt(2*n,0);
    set<int> active={0};
    auto ch=[&](int r,int x)
    {
        update(1,1,2*n-1,1,r,x);
        if(cnt[r]==0) active.insert(r);
        cnt[r]+=x;
        if(cnt[r]==0) active.erase(r);
    };
    set<array<int,2>> p;
    while(m--)
    {
        int x,y;
        cin >> x >> y;
        int d=0;
        if(!p.contains({x,y}))
        {
            d=1;
            p.insert({x,y});
        }
        else
        {
            d=-1;
            p.erase({x,y});
        }
        ch(y+abs(x-k),d);
        cout << query(1,1,2*n-1,1,(*active.rbegin())) << "\n";
    }
    return 0;
}