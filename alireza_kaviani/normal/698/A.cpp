#include <bits/stdc++.h>
using namespace std;

typedef long long                   ll;
typedef long double                 ld;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<double,double>         pdd;
typedef pair<ld,ld>                 pld;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define Mp                          make_pair
#define endt                        '\t'
#define ends                        ' '
#define error(x)                    cerr << #x << " = " << x << endl

int dp[150][3];

int main()
{
    int n;
    cin >> n;

    for(int i=1;i<=n;i++)
    {
        int t;
        cin >> t;

        dp[i][0]=max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
        if(t==1 || t==3)
        {
            dp[i][1]=max(dp[i-1][0],dp[i-1][2])+1;
        }

        if(t==2 || t==3)
        {
            dp[i][2]=max(dp[i-1][1],dp[i-1][0])+1;
        }
    }

    cout << n-max(dp[n][0],max(dp[n][1] , dp[n][2]));
}