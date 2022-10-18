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

#define md (ll)(998244353)

#define arr (int)(1e5+10)

inline void add(int& a,int b)
{
    a+=b;
    while (a>=md){
        a-=md;
    }
    while (a<0){
        a+=md;
    }
}

int a[arr];
int dp[arr][201][2];
int addd[202][2];

inline void add_on_seg(const int l,const int r,const int id,const int val)
{
    if (l>r){
        return;
    }
    add(addd[l][id],val);
    add(addd[r+1][id],-val);
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    if (a[1]==-1){
        for (int i=1;i<=200;i++){
            dp[1][i][0]=1;
        }
    }
    else{
        dp[1][a[1]][0]=1;
    }
    for (int i=1;i<n;i++){
        for (int last=1;last<=200;last++){
            if (a[i+1]!=-1){
                if (last<=a[i+1]){
                    add(dp[i+1][a[i+1]][(a[i+1]<=last)],dp[i][last][0]);
                }
                add(dp[i+1][a[i+1]][(a[i+1]<=last)],dp[i][last][1]);
            }
            else{
//                for (int l=1;l<=200;l++){
//                    if (last<=l){
//                        add(dp[i+1][l][(l<=last)],dp[i][last][0]);
//                    }
////                    cout<<i+1<<" "<<a[i+1]<<" "<<(a[i+1]<=last)<<"\n";
//                    add(dp[i+1][l][(l<=last)],dp[i][last][1]);
//                }

                /// first easy

                add(dp[i+1][last][1],dp[i][last][0]);

                add_on_seg(last+1,200,0,dp[i][last][0]);

                /// segond

                add_on_seg(1,last,1,dp[i][last][1]);
                add_on_seg(last+1,200,0,dp[i][last][1]);
            }
        }

        int cur0=0;
        int cur1=0;
        for (int j=1;j<=200;j++){
            add(cur0,addd[j][0]);
            add(cur1,addd[j][1]);

            add(dp[i+1][j][0],cur0);
            add(dp[i+1][j][1],cur1);
        }
        memset(addd,0,sizeof(addd));
    }
//    for (int i=1;i<=n;i++){
//        for (int j=1;j<=200;j++){
//            if (dp[i][j][0]){
//                cout<<"dp["<<i<<"]["<<j<<"][0] :: "<<dp[i][j][0]<<"\n";
//            }
//            if (dp[i][j][1]){
//                cout<<"dp["<<i<<"]["<<j<<"][1] :: "<<dp[i][j][1]<<"\n";
//            }
//        }
//    }
    int ans=0;
    for (int i=1;i<=200;i++){
        add(ans,dp[n][i][1]);
    }
    cout<<ans<<"\n";
}