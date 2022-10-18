#pragma GCC optimize("O3")
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

void inc(int& a,int b)
{
    a+=b;
    a%=md;
    a+=md;
    a%=md;
}

int len[arr];
int dp[ar][ar][2]; /// [pref][cnt_bit][is_equal]

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    string s;
    int k;
    cin>>s>>k;
    if (k==0){
        return cout<<1<<"\n", 0;
    }
    for (int i=2;i<=1000;i++){
        len[i]=len[__builtin_popcountll(i)]+1;
    }
    dp[0][0][1]=1;
    for (int i=0;i<len(s);i++){
        for (int j=0;j<=i;j++){
            /// from [i][j][1]
            if (s[i]=='1'){
                inc(dp[i+1][j+1][1],dp[i][j][1]);
                inc(dp[i+1][j][0],dp[i][j][1]);
            }
            else{
                inc(dp[i+1][j][1],dp[i][j][1]);
            }
            /// from [i][j][0]
            inc(dp[i+1][j+1][0],dp[i][j][0]);
            inc(dp[i+1][j][0],dp[i][j][0]);
        }
    }
    int ans=0;
    for (int i=1;i<=len(s);i++){
        if (len[i]+1==k){
//            cout<<i<<" !!\n";
            inc(ans,dp[len(s)][i][0]);
            inc(ans,dp[len(s)][i][1]);
        }
    }
    if (k==1){
        inc(ans,-1);
    }
    cout<<ans<<"\n";
}