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

int dp[arr][2];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    string s;
    cin>>s;
    reverse(all(s));

    for (int i=0;i<arr;i++){
        dp[i][0]=-1e18;
        dp[i][1]=-1e18;
    }
    dp[0][0]=0;
    for (int i=1;i<=len(s);i++){
        for (int a=0;a<10;a++){
            for (int b=0;b<10;b++){
                for (int c=0;c<2;c++){
                    int cur=(a+b+c)%10;
                    int cur1=(a+b+c)/10;
                    if (cur==s[i-1]-'0'){
                        dp[i][cur1]=max(dp[i][cur1],dp[i-1][c]+a+b);
                    }
                }
            }
        }
    }
    cout<<dp[len(s)][0]<<"\n";
}