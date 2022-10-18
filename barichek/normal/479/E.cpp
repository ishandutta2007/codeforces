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
const ll md=1e9+7;
const ld eps=1e-6;

///---program start---///

ll dp[5001][5001];
ll pref[5001];

int main()
{
    int n,k,a,b;
    cin>>n>>a>>b>>k;
    dp[0][a]=1;
    pref[0]=0;
    for (int i=1;i<=n;i++)
        pref[i]=(pref[i-1]+dp[0][i]+md)%md;
    for (int i=1;i<=k;i++)
    {
        for (int j=1;j<=n;j++)
        {
            if (j==b) continue;
            if (j<b)
            {
                int mid=(j+b)/2-((j+b)%2==0);
                dp[i][j]=(pref[mid]-dp[i-1][j]+md)%md;
            }
            else
            {
                int mid=(j+b)/2+1;
                dp[i][j]=(pref[n]-pref[mid-1]-dp[i-1][j]+md)%md;
            }
        }
        pref[0]=0;
        for (int j=1;j<=n;j++)
            pref[j]=(pref[j-1]+dp[i][j]+md)%md;
    }
    ll ans=0;
    for (int i=1;i<=n;i++)
        //cout<<i<<" "<<dp[k][i]<<"\n",
        ans=(ans+dp[k][i]+md)%md;
    cout<<ans;
}