#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const int N=1e5+10,M=35,K=16;
const ll mod=998244353;
ll basis[M];

bool add(ll x)
{
    for (int i=M-1;i>=0 && x;i--)
        if ((x>>i)&1)
        {
            if (basis[i]==0)
            {
                basis[i]=x;
                return true;
            }
            x^=basis[i];
        }
    return false;
}

int n,m,dp[K+1][1<<K][M+1];
ll cs=1;

void read()
{
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        ll x;
        cin>>x;
        if (!add(x)) cs=cs*2%mod;
    }
}

void dfs(int id,ll mask)
{
    if (id<K)
    {
        int sl=__builtin_popcountll(mask);
        mask &=(1<<K)-1;
        sl-=__builtin_popcountll(mask);
        dp[id+1][mask][sl]++;
        return;
    }
    dfs(id-1,mask);
    if (basis[id]) dfs(id-1,mask ^ basis[id]);
}

void update(int &x,int y) { x=(x+y)%mod; }

void process()
{
    dfs(M-1,0);
    for (int i=K;i;i--)
        for (int mask=0;mask<(1<<i);mask++)
            for (int sl=0;sl<=M-i;sl++)
            {
                update(dp[i-1][mask & ((1<<(i-1))-1)][sl+(mask>>(i-1))],dp[i][mask][sl]);
                if (basis[i-1]==0) continue;
                int nmask=(mask ^ basis[i-1]);
                update(dp[i-1][nmask & ((1<<(i-1))-1)][sl+(nmask>>(i-1))],dp[i][mask][sl]);
            };
    for (int i=0;i<=m;i++) cout<<cs*dp[0][0][i]%mod<<" ";
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    read();
    process();
    return 0;
}