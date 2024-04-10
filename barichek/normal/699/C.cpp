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
typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

const ll maxll=numeric_limits<ll>::max();
const int maxint=numeric_limits<int>::max();
const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ll md=1e9+7;
const ld eps=1e-6;

///---program start---///
/*
bool a1[1000];
bool a2[1000];

int a()
{
    int n,m;
    cin>>n>>m;
    char a[n][m];
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            cin>>a[i][j];
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            if (a[i][j]=="*")
                a1[i]=true;
                a2[j]=true;

}*/

int n,dp[1000][3];

int main()
{
    cin>>n;
    int zn;
    cin>>zn;
    if (zn==1)
        dp[0][2]=1;
    if (zn==2)
        dp[0][1]=1;
    if (zn==3)
        dp[0][2]=1,
        dp[0][1]=1;
    for (int i=1;i<n;i++)
    {
        cin>>zn;
        if (zn==0)
        {
            dp[i][0]=max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
            dp[i][1]=max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
            dp[i][2]=max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
        }
        if (zn==1)
        {
            dp[i][0]=max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
            dp[i][1]=max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
            //dp[i][1]=0;
            dp[i][2]=max(dp[i-1][0]+1,max(dp[i-1][1]+1,dp[i-1][2]));
        }
        if (zn==2)
        {
            dp[i][0]=max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
            dp[i][1]=max(dp[i-1][0]+1,max(dp[i-1][1],dp[i-1][2]+1));
            //dp[i][1]=0;
            dp[i][2]=max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
        }
        if (zn==3)
        {
            dp[i][0]=max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
            dp[i][1]=max(dp[i-1][0]+1,max(dp[i-1][1],dp[i-1][2]+1));
            //dp[i][1]=0;
            dp[i][2]=max(dp[i-1][0]+1,max(dp[i-1][1]+1,dp[i-1][2]));
        }
    }
    cout<<n-max(dp[n-1][0],max(dp[n-1][2],dp[n-1][1]));
}