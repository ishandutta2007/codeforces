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
const ld eps=1e-10;

///---program start---///

#define int ll
#define maxll (int)1e17

int dp[101][101][101];

main()
{
    fast;
    for (int i=0;i<101;i++)
        for (int j=0;j<101;j++)
            for (int p=0;p<101;p++)
                dp[i][j][p]=maxll;
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll> c;
    c.resize(n+1);
    for (int i=1;i<=n;i++)
        cin>>c[i];
    ll cost[ar][ar];
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            cin>>cost[i][j];
    for (int i=1;i<=m;i++)
        dp[0][0][0]=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=k;j++)
            for (int p=1;p<=m;p++)
            {
                //cout<<i<<" "<<j<<" "<<p<<" !\n";
                if (c[i]==0)
                {
                    for (int take=0;take<=m;take++)
                        dp[i][j][p]=min(dp[i][j][p],dp[i-1][j-(p!=take)][take]+cost[i][p]);
                }
                elif (p==c[i])
                    for (int last=0;last<=m;last++)
                        dp[i][j][p]=min(dp[i][j][p],dp[i-1][j-(last!=c[i])][last]);
                //cout<<dp[i][j][p]<<" !\n";
            }
    ll res=maxll;
    for (int i=1;i<=m;i++)
        res=min(res,dp[n][k][i]);
    if (res==maxll) return cout<<-1, 0;
    cout<<res;
}