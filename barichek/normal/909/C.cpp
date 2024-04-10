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
///#define int long long

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

#define ar (int)(5000+10)

inline void inc(int& a,int b)
{
    a+=b;
    a%=md;
    a+=md;
    a%=md;
}

int dp[ar][ar][2]; /// pref balance is_open(1 - all bad)
int pref[ar];
int type[arr];

inline int sum(int i,int l,int r)
{
    int res=0;
    inc(res,pref[r]);
    if (l){
        inc(res,-pref[l-1]);
    }
    return res;
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        char c;
        cin>>c;
        type[i]=(c=='s'?1:2);
    }
    dp[0][0][0]=1;
    for (int i=0;i<=n;i++){
        for (int j=0;j<=n;j++){
            if (i){
                if (type[i]==1){
//                    cout<<"inc :: "<<i<<" "<<j<<" "<<0<<" :: "<<j<<","<<n<<"\n";
                    inc(dp[i][j][0],sum(i-1,j,n));
//                    cout<<"kek :: "<<dp[i][j][0]<<"\n";
                }
                else{
                    if (j>=1){
                        inc(dp[i][j][1],sum(i-1,j-1,n));
                    }
                }
            }
            if (i<n){
                /// from dp[i][j][0]
//                if (type[i+1]==1){
//                    /// for all 0<=l<=j
//                    /// inc(dp[i+1][l][0],dp[i][j][0]);
//                }
//                else{
//                    /// for all 1<=l<=j+1
//                    /// inc(dp[i+1][l][1],dp[i][j][0]);
//                }

                /// from dp[i][j][1]
//                cout<<"i :: "<<i<<" ::: "<<type[i+1]<<"\n";
                if (type[i+1]==1){
                    inc(dp[i+1][j][0],dp[i][j][1]);
                }
                else{
//                    cout<<"from :: "<<i<<" "<<j<<" "<<1<<" to "<<i+1<<" "<<j+1<<" "<<1<<"\n";
//                    cout<<"val :: "<<dp[i][j][1]<<"\n";
                    inc(dp[i+1][j+1][1],dp[i][j][1]);
//                    cout<<dp[i+1][j+1][1]<<"\n";
                }
            }
        }
        for (int j=0;j<=n;j++){
//            cout<<"dp["<<i<<"]["<<j<<"][0] :: "<<dp[i][j][0]<<"\n";
//            cout<<"dp["<<i<<"]["<<j<<"][1] :: "<<dp[i][j][1]<<"\n";
            pref[j]=((j==0?0:pref[j-1])+dp[i][j][0])%md;
//            cout<<"pref["<<i<<"]["<<j<<"] :: "<<pref[i][j]<<"\n";
        }
    }
    int ans=0;
    for (int i=0;i<=n;i++){
        inc(ans,dp[n][i][0]);
    }
    cout<<ans<<"\n";
}