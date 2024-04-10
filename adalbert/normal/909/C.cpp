#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define m_p make_pair
#define get leirogoerg
#define files(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
#define left dogjreg
#define right dgfdogjreg
typedef long long ll;
typedef double ld;
const int arr=2e5+1000;

int dp[5010][5010];
const int md=1e9+7;
char a[5010];
signed main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];

    dp[1][1]=1;

    for (int i=2;i<=n;i++)
        if (a[i-1]=='f')
        {
            for (int j=2;j<=n;j++)
            {
                dp[i][j]+=dp[i-1][j-1];
                dp[i][j]%=md;
            }
        } else
        {
            int sum=0;
            for (int j=n;j>=1;j--)
            {
                sum+=dp[i-1][j];
                sum%=md;
                dp[i][j]+=sum;
                dp[i][j]%=md;
            }
        }

    int res=0;
    for (int i=0;i<=n;i++)
    {
        res+=dp[n][i];
        res%=md;
    }
    cout<<res;
}