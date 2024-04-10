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

const ll maxll=numeric_limits<ll>::max();
const int maxint=numeric_limits<int>::max();
const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ll md=1e9+7;
const ld eps=1e-6;

///---program start---///

#define maxint maxll ///sukotay ibanutiy blyat

ll cost[arr],dp[arr][2];
vector<string> vec1,vec2;
int n;

int main()
{
    for (int i=0;i<arr;i++)
        dp[i][0]=maxint,dp[i][1]=maxint;
    cin>>n;
    vec1.resize(n);
    vec2.resize(n);
    for (int i=0;i<n;i++)
        cin>>cost[i];
    for (int i=0;i<n;i++)
        cin>>vec1[i];
    for (int i=0;i<n;i++)
    {
        string dop=vec1[i];
        reverse(all(dop));
        vec2[i]=dop;
    }
    dp[0][0]=0;
    dp[0][1]=cost[0];
    for (int i=1;i<n;i++)
    {
        if (vec1[i]>=vec1[i-1]&&vec1[i]>=vec2[i-1])
            dp[i][0]=min(dp[i-1][0],dp[i-1][1]);
        elif (vec1[i]>=vec1[i-1])
            dp[i][0]=dp[i-1][0];
        elif (vec1[i]>=vec2[i-1])
            dp[i][0]=dp[i-1][1];

        if (vec2[i]>=vec1[i-1]&&vec2[i]>=vec2[i-1])
            dp[i][1]=min(dp[i-1][0],dp[i-1][1]);
        elif (vec2[i]>=vec1[i-1])
            dp[i][1]=dp[i-1][0];
        elif (vec2[i]>=vec2[i-1])
            dp[i][1]=dp[i-1][1];

        if (dp[i][1]!=maxint) dp[i][1]+=cost[i];
        if (dp[i][1]==maxint&&dp[i][0]==maxint) return cout<<-1, 0;
    }
    cout<<min(dp[n-1][0],dp[n-1][1]);
}