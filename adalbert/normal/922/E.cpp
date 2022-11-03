#include <bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#define time pdojegoritg
#define left eorgjrptgj
#define right rtyjtokh
#define get rgjeoig
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int arr=5e5+100;

int dp[1100][11000];
int sum[1100],c[1100],cost[1100];

signed main()
{
    int n,w,b,x;
    cin>>n>>w>>b>>x;

    for (int i=1;i<=n;i++)
    {
        cin>>c[i];
        sum[i]=sum[i-1]+c[i];
    }

    for (int i=1;i<=n;i++)
        cin>>cost[i];


    for (int i=0;i<=n;i++)
        for (int j=0;j<=sum[i];j++)
        dp[i][j]=-1;

    dp[0][0]=w;

    for (int i=1;i<=n;i++)
        for (int s1=0;s1<=sum[i-1];s1++)
            if (dp[i-1][s1]!=-1)
            {
                int mx=0;
                int sum=dp[i-1][s1]+x;
                sum=min(sum,w+s1*b);
                dp[i][s1]=max(dp[i][s1],sum);
                while (mx<c[i] && sum-cost[i]>=0)
                {
                    sum-=cost[i];
                    mx++;
                    dp[i][s1+mx]=max(dp[i][s1+mx],sum);
                }
            }
    int ans=0;
    for (int s1=0;s1<=sum[n];s1++)
        if (dp[n][s1]!=-1)
        ans=max(ans,s1);
    cout<<ans;
}
/*
*/