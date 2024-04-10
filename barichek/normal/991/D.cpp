#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
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

void maximize(int& a,int b)
{
    if (a<b){
        a=b;
    }
}

string s[2];
int dp[arr][4];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    cin>>s[0]>>s[1];

    int n=len(s[0]);

    for (int i=0;i<n;i++){
        for (int j=0;j<4;j++){
            maximize(dp[i+1][0],dp[i][j]);
        }
        for (int j=0;j<4;j++){
            /// if push 1
            if (j==0&&i!=n-1&&s[0][i]=='0'&&s[1][i]=='0'&&s[0][i+1]=='0'){
                maximize(dp[i+1][1],dp[i][j]+1);
            }
            /// if push 2
            if (((j&1)==0)&&i!=n-1&&s[0][i]=='0'&&s[1][i+1]=='0'&&s[0][i+1]=='0'){
                maximize(dp[i+1][3],dp[i][j]+1);
            }
            /// if push 3
            if (((j&2)==0)&&i!=n-1&&s[1][i]=='0'&&s[1][i+1]=='0'&&s[0][i+1]=='0'){
                maximize(dp[i+1][3],dp[i][j]+1);
            }
            /// if push 4
            if (j==0&&i!=n-1&&s[0][i]=='0'&&s[1][i]=='0'&&s[1][i+1]=='0'){
                maximize(dp[i+1][2],dp[i][j]+1);
            }
        }
    }

    int ans=0;
    for (int i=0;i<arr;i++){
        for (int j=0;j<4;j++){
//            if (dp[i][j]>0){
//                cout<<i<<" "<<j<<" :: "<<dp[i][j]<<"\n";
//                return 0;
//            }
            maximize(ans,dp[i][j]);
        }
    }
    cout<<ans<<"\n";
}