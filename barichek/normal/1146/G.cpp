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

int dp[51][51][51];
int l[51];
int r[51];
int x[51];
int c[51];

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n,h,m;
    cin>>n>>h>>m;
    for (int i=0;i<m;i++){
        cin>>l[i]>>r[i]>>x[i]>>c[i];
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            for (int k=0;k<=h;k++){
                dp[i][j][k]=-1e9;
            }
        }
    }
    for (int i=n;i>=1;i--){
        for (int j=i;j<=n;j++){
            for (int cur_h=0;cur_h<=h;cur_h++){
                for (int fm=i;fm<=j;fm++){
                    int pen=0;
                    for (int k=0;k<m;k++){
                        if (l[k]>=i&&r[k]<=j&&l[k]<=fm&&r[k]>=fm&&cur_h>x[k]){
                            pen+=c[k];
                        }
                    }
                    int cur_res=cur_h*cur_h+(fm==i?0:dp[i][fm-1][cur_h])+(fm==j?0:dp[fm+1][j][cur_h])-pen;
                    dp[i][j][cur_h]=max(dp[i][j][cur_h],cur_res);
                }
//                cout<<i<<" "<<j<<" "<<cur_h<<" :: "<<dp[i][j][cur_h]<<"\n";
                if (cur_h){
                    dp[i][j][cur_h]=max(dp[i][j][cur_h],dp[i][j][cur_h-1]);
                }
            }
        }
    }
    int ans=-1e9;
    for (int i=0;i<=h;i++){
        ans=max(ans,dp[1][n][i]);
    }
    cout<<ans<<"\n";
}