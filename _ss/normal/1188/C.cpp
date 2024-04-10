#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const ll maxn=1e3+100,mod=998244353,maxv=1e5;
int a[maxn],n,k;
ll s[maxv+100],f[maxn][maxn];

void read()
{
    cin>>n>>k;
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
}

ll dp(int v)
{
    for (int i=0;i<=n;i++)
        for (int j=0;j<=k;j++) f[i][j]=0;
    int j=1,i=1;
    while (i<=n)
    {
        while (j<i && a[i]-a[j]>=v) j++;
        if (j && a[i]-a[j]<v) j--;
        f[i][1]=i;
        if (a[i]-a[j]>=v) for (int t=2;t<=k;t++) f[i][t]=(f[i-1][t]+f[j][t-1])%mod;
        i++;
    }
    return f[n][k];
}

void process()
{
    sort(a+1,a+n+1);
    for (int i=1;i<=maxv/(k-1);i++) s[i]=dp(i);
    for (int i=1;i<=maxv/(k-1);i++) s[i]=(s[i]-s[i+1]+mod)%mod;
    ll ans=0;
    for (int i=1;i<=maxv/(k-1);i++) ans=(ans+(s[i]*i)%mod)%mod;
    cout<<ans;
}

int main()
{
    //freopen("ss.inp","r",stdin);
    read();
    process();
    return 0;
}