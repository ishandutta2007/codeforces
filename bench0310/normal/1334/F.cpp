#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=500005;
vector<int> a(N,0);
vector<int> p(N,0);
vector<int> tree[4*N];
vector<ll> sum[4*N];
vector<ll> neg(4*N,0);
auto cmp=[&](int x,int y)->bool{return (a[x]<a[y]);};

void build(int idx,int l,int r)
{
    if(l==r)
    {
        tree[idx]={l};
        sum[idx]={max(0,p[l]),0};
        neg[idx]=min(0,p[l]);
    }
    else
    {
        int m=(l+r)/2;
        build(2*idx,l,m);
        build(2*idx+1,m+1,r);
        tree[idx].reserve(r-l+1);
        merge(tree[2*idx].begin(),tree[2*idx].end(),tree[2*idx+1].begin(),tree[2*idx+1].end(),back_inserter(tree[idx]),cmp);
        sum[idx].assign(r-l+2,0);
        for(int i=r-l;i>=0;i--) sum[idx][i]=sum[idx][i+1]+max(0,p[tree[idx][i]]);
        neg[idx]=neg[2*idx]+neg[2*idx+1];
    }
}

ll query(int idx,int l,int r,int ql,int qr,int val)
{
    if(ql>qr) return 0;
    if(l==ql&&r==qr)
    {
        int t=(lower_bound(tree[idx].begin(),tree[idx].end(),val,cmp)-tree[idx].begin());
        return sum[idx][t]+neg[idx];
    }
    int m=(l+r)/2;
    return query(2*idx,l,m,ql,min(qr,m),val)+query(2*idx+1,m+1,r,max(ql,m+1),qr,val);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    a[n+1]=n+1;
    for(int i=1;i<=n;i++) cin >> p[i];
    build(1,1,n);
    int m;
    cin >> m;
    vector<int> b(m+2,0);
    for(int i=1;i<=m;i++) cin >> b[i];
    b[m+1]=n+1;
    const ll inf=(1ll<<60);
    vector<ll> dp(n+2,inf);
    dp[0]=0;
    vector<int> occ[n+2];
    for(int i=0;i<=n+1;i++) occ[a[i]].push_back(i);
    for(int i=0;i<=m;i++)
    {
        int now=b[i];
        a[n+2]=now+1;
        int nxt=b[i+1];
        vector<array<int,2>> e;
        for(int x:occ[now]) e.push_back({x,0});
        for(int x:occ[nxt]) e.push_back({x,1});
        sort(e.begin(),e.end());
        ll mn=inf;
        bool ok=0;
        int px=0;
        for(auto [x,t]:e)
        {
            if(ok) mn+=query(1,1,n,px+1,x-1,n+2);
            if(t==0)
            {
                if(ok==0)
                {
                    if(dp[x]!=inf)
                    {
                        mn=dp[x];
                        ok=1;
                    }
                }
                else mn=min(mn+min(0,p[x]),dp[x]);
            }
            else if(ok)
            {
                dp[x]=mn;
                mn+=min(0,p[x]);
            }
            px=x;
        }
    }
    if(dp[n+1]!=inf) cout << "YES\n" << dp[n+1] << "\n";
    else cout << "NO\n";
    return 0;
}