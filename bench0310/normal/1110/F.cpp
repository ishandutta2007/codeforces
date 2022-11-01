#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=500005;
int n;
vector<array<int,2>> v[N];
vector<ll> d(4*N,0);
vector<ll> tree(4*N,0);
vector<ll> lazy(4*N,0);
vector<int> tout(N,0);
int tcnt=0;
const ll inf=(1ll<<60);
vector<array<int,3>> queries[N];
vector<ll> res(N,0);

void dfs(int a)
{
    tcnt++;
    for(auto [to,w]:v[a])
    {
        d[to]=d[a]+w;
        dfs(to);
    }
    tout[a]=tcnt;
}

void build(int idx,int l,int r)
{
    if(l==r) tree[idx]=(v[l].size()==0?d[l]:inf);
    else
    {
        int m=(l+r)/2;
        build(2*idx,l,m);
        build(2*idx+1,m+1,r);
        tree[idx]=min(tree[2*idx],tree[2*idx+1]);
    }
}

void push(int idx)
{
    for(int i=0;i<=1;i++)
    {
        tree[2*idx+i]+=lazy[idx];
        lazy[2*idx+i]+=lazy[idx];
    }
    lazy[idx]=0;
}

void update(int idx,int l,int r,int ql,int qr,int val)
{
    if(ql>qr) return;
    if(l==ql&&r==qr)
    {
        tree[idx]+=val;
        lazy[idx]+=val;
    }
    else
    {
        int m=(l+r)/2;
        push(idx);
        update(2*idx,l,m,ql,min(qr,m),val);
        update(2*idx+1,m+1,r,max(ql,m+1),qr,val);
        tree[idx]=min(tree[2*idx],tree[2*idx+1]);
    }
}

ll query(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return inf;
    if(l==ql&&r==qr) return tree[idx];
    int m=(l+r)/2;
    push(idx);
    return min(query(2*idx,l,m,ql,min(qr,m)),query(2*idx+1,m+1,r,max(ql,m+1),qr));
}

void reroot(int a,int b,int w,int x)
{
    update(1,1,n,b,tout[b],-w*x);
    update(1,1,n,1,b-1,w*x);
    update(1,1,n,tout[b]+1,n,w*x);
}

void solve(int a,int p=0,int up=0)
{
    for(auto [l,r,id]:queries[a]) res[id]=query(1,1,n,l,r);
    for(auto [to,w]:v[a])
    {
        reroot(a,to,w,1);
        solve(to,a,w);
    }
    if(p!=0) reroot(p,a,up,-1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> n >> q;
    for(int i=2;i<=n;i++)
    {
        int p,w;
        cin >> p >> w;
        v[p].push_back({i,w});
    }
    for(int i=1;i<=q;i++)
    {
        int a,l,r;
        cin >> a >> l >> r;
        queries[a].push_back({l,r,i});
    }
    dfs(1);
    build(1,1,n);
    solve(1);
    for(int i=1;i<=q;i++) cout << res[i] << "\n";
    return 0;
}