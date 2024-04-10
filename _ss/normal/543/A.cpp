#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const int N=510;
ll n,m,b,mod,a[N],dp[N][N];

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>b>>mod;
    for (int i=1;i<=n;i++) cin>>a[i];
    dp[0][0]=1;
    for (int i=1;i<=n;i++)
        for (int sl=1;sl<=m;sl++)
            for (int er=0;er<=b;er++)
                if (er-a[i]>=0) dp[sl][er]=(dp[sl][er]+dp[sl-1][er-a[i]])%mod;
    ll res=0;
    for (int t=0;t<=b;t++) res=(res+dp[m][t])%mod;
    cout<<res;
    return 0;
}