#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(),vr.end()
#define vi vector<int>
#define vll vector<ll>
const int N=5e3+10;
const ll mod=1e9+7;
int n,q,a[N],k;

void read()
{
    cin>>n>>k>>q;
    for (int i=1;i<=n;i++) cin>>a[i];
}

ll dp[N][N],cnt[N];

void process()
{
    for (int i=1;i<=n;i++) dp[0][i]=1;
    for (int i=1;i<=k;i++)
        for (int j=1;j<=n;j++) dp[i][j]=(dp[i-1][j-1]+dp[i-1][j+1])%mod;
    for (int i=1;i<=n;i++)
        for (int j=0;j<=k;j++) cnt[i]=(cnt[i]+dp[j][i]*dp[k-j][i])%mod;
    ll res=0;
    for (int i=1;i<=n;i++) res=(res+cnt[i]*a[i])%mod;
    for (int i=1,p,x;i<=q;i++)
    {
        cin>>p>>x;
        res=(res+cnt[p]*(x-a[p])+mod*mod)%mod;
        a[p]=x;
        cout<<res<<"\n";
    }
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