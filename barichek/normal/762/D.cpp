#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define all(a) a.begin(),a.end()
#define elif else if
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;
#define int long long

typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;

const int maxint=numeric_limits<int>::max();
const ll maxll=numeric_limits<ll>::max();
const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ld eps=1e-10;
const ll md=1e9+7;

///---program start---///

int dp[arr][8][3];
int a[arr][3];

void maximize(int &a,int b)
{
    if (a<b) a=b;
}

bool had(int a,int b)
{
    return (a&(1ll<<b))>0;
}

main()
{
    int n;
    cin>>n;
    for (int i=0;i<3;i++)
        for (int j=0;j<n;j++)
            cin>>a[j][i];
    for (int i=0;i<arr;i++)
        for (int j=0;j<8;j++)
            for (int k=0;k<3;k++)
                dp[i][j][k]=-1e18;
    dp[0][1][0]=a[0][0];
    for (int i=0;i<n;i++)
    {
        maximize(dp[i+1][7][2],dp[i][1][0]+a[i][1]+a[i][2]+a[i+1][0]+a[i+1][1]+a[i+1][2]);
        maximize(dp[i+1][7][0],dp[i][4][2]+a[i][0]+a[i][1]+a[i+1][0]+a[i+1][1]+a[i+1][2]);
        for (int j=0;j<8;j++)
            for (int k=0;k<3;k++)
                if (had(j,k)&&dp[i][j][k]!=-1e18)
                {
                    if (k!=0&&!had(j,k-1))
                        maximize(dp[i][j|(1ll<<(k-1))][k-1],dp[i][j][k]+a[i][k-1]);
                    if (k!=2&&!had(j,k+1))
                        maximize(dp[i][j|(1ll<<(k+1))][k+1],dp[i][j][k]+a[i][k+1]);
                    maximize(dp[i+1][1ll<<(k)][k],dp[i][j][k]+a[i+1][k]);
                }
    }
    int ans=-1e18;
    for (int j=0;j<8;j++)
        maximize(ans,dp[n-1][j][2]);
    cout<<ans;
}