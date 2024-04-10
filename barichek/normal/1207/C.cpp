//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) name!=""?freopen(name".in","r",stdin),freopen(name".out","w",stdout):0
#define all(a) a.begin(),a.end()
#define len(a) (int)(a.size())
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

const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ld eps=1e-10;
const ll md=1e9+7;

///---program start---///

int dp[arr][2];

void minimize(int& a,int b)
{
    if (a>b){
        a=b;
    }
}

void solve()
{
    int n,a,b;
    cin>>n>>a>>b;
    for (int i=0;i<=n;i++){
        dp[i][0]=1e18;
        dp[i][1]=1e18;
    }
    string s;
    cin>>s;
    dp[0][0]=b;
    for (int i=0;i<n;i++){
        for (int j=0;j<2;j++){
//            cout<<i<<" "<<j<<" "<<dp[i][j]<<" !!!\n";
            for (int to=0;to<2;to++){
                if ((j==1&&to==1)||s[i]=='0'){
                    minimize(dp[i+1][to],dp[i][j]+(1+(j!=to))*a+(to+1)*b);
                }
            }
        }
    }
    cout<<dp[n][0]<<"\n";
}

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int test;
    cin>>test;
    while (test--){
        solve();
    }
}