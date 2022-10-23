#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll N=2e3+10,mod=998244353;
ll dp[N][N];
int n,a[N][N],cnt[N],bit1[N],bit2[N],mark[N];

void add(int bit[],int v)
{
    for (int i=v;i<=n;i+=(i&-i)) bit[i]++;
}

int get(int bit[],int v)
{
    int res=0;
    for (int i=v;i;i-=(i&-i)) res+=bit[i];
    return res;
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++) cin>>a[i][j];
    dp[0][0]=1;
    for (int i=1;i<=n;i++) dp[i][0]=dp[i-1][0]*i%mod;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=i;j++) dp[i][j]=(dp[i][j-1]-dp[i-1][j-1]+mod)%mod;
    ll val=1,ans=0;
    for (int i=n;i>1;i--)
    {
        for (int j=1;j<=n;j++) bit1[j]=bit2[j]=mark[j]=0,cnt[j]=2;
        int sl=n;
        for (int j=1;j<=n;j++)
        {
            if (cnt[a[i-1][j]]==2) sl--,add(bit2,a[i-1][j]);
            cnt[a[i-1][j]]--;
            int t1=a[i][j]-1-get(bit1,a[i][j]-1),t2=a[i][j]-1-get(bit2,a[i][j]-1);
            if (a[i-1][j]<a[i][j] && !mark[a[i-1][j]]) t1--;
            ans=(ans+val*dp[n-j][sl]%mod*(t1-t2))%mod;
            if (sl) ans=(ans+val*dp[n-j][sl-1]%mod*t2)%mod;
            if (cnt[a[i][j]]==2) sl--,add(bit2,a[i][j]);
            cnt[a[i][j]]--;
            add(bit1,a[i][j]);
            mark[a[i][j]]=1;
        }
        val=val*dp[n][n]%mod;
    }
    for (int i=1;i<=n;i++) bit1[i]=0;
    for (int i=1;i<=n;i++)
    {
        int t1=a[1][i]-1-get(bit1,a[1][i]-1);
        ans=(ans+val*dp[n-i][0]%mod*t1)%mod;
        add(bit1,a[1][i]);
    }
    cout<<ans;
    return 0;
}