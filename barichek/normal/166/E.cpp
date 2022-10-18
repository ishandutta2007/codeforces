#include <bits/stdc++.h>
#include <ext/rope>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define all(a) a.begin(),a.end()
#define elif else if
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;
using namespace __gnu_cxx;

typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;

const ll maxll=numeric_limits<ll>::max();
const int maxint=numeric_limits<int>::max();
const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ll md=1e9+7;
const ld eps=1e-6;

///---program start---///

int dp[10000001][4];

int main()
{
    int n;
    cin>>n;
    dp[0][0]=1;
    for (int i=1;i<=n;i++)
    {
        dp[i][0]=(0ll+dp[i-1][1]+dp[i-1][2]+dp[i-1][3])%md;
        dp[i][1]=(0ll+dp[i-1][0]+dp[i-1][2]+dp[i-1][3])%md;
        dp[i][2]=(0ll+dp[i-1][0]+dp[i-1][1]+dp[i-1][3])%md;
        dp[i][3]=(0ll+dp[i-1][0]+dp[i-1][1]+dp[i-1][2])%md;
    }
    cout<<dp[n][0];
}