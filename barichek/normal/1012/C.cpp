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
//#define int long long

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

#define ar (int)(5e3+10)

int dp[ar][ar][2][2];

int n;
int a[arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    for (int i=0;i<ar;i++){
        for (int j=0;j<ar;j++){
            for (int k=0;k<2;k++){
                for (int p=0;p<2;p++){
                    dp[i][j][k][p]=1e9;
                }
            }
        }
    }

    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        a[i]+=2;
    }

    dp[0][0][0][0]=0;
    dp[0][0][0][1]=0;
    for (int pos=1;pos<=n;pos++){
        for (int cnt=0;cnt<=pos;cnt++){
            for (int last=0;last<2;last++){
                for (int is_smaller_than_next=0;is_smaller_than_next<2;is_smaller_than_next++){
                    int& res=dp[pos][cnt][last][is_smaller_than_next];

                    int cur_value=a[pos];
                    if (is_smaller_than_next){
                        cur_value=min(a[pos],a[pos+1]-1);
                    }

                    if (last){
                        if (cnt){
                            /// if go dp[pos-1][cnt-1][0]
                            res=min(res,dp[pos-1][cnt-1][0][1]+max(0,(a[pos-1])-(cur_value-1)));
                        }
                    }
                    else{
                        if (pos!=1){
                            /// if go dp[pos-1][cnt-1][1]
                            res=min(res,dp[pos-1][cnt][1][0]+max(0,(cur_value)-(a[pos-1]-1)));
                        }

                        /// if go dp[pos-1][cnt-1][0]
                        res=min(res,dp[pos-1][cnt][0][0]);
                    }
                }
            }
        }
    }
    for (int i=1;i<=(n+1)/2;i++){
        int res=min({dp[n][i][0][0],dp[n][i][1][0]});
        cout<<res<<" ";
    }
    cout<<"\n";
}