#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) name!=""?freopen(name".in","r",stdin),freopen(name".out","w",stdout):0
#define files_ds(name) name!=""?freopen(name".dat","r",stdin),freopen(name".sol","w",stdout):0
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

int c[arr];
int cost[arr];
ll dp[1001][10001];
int pref[arr];

inline void maximize(ll& a,ll b)
{
    if (a<b){
        a=b;
    }
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    for (int i=0;i<1001;i++){
        for (int j=0;j<10001;j++){
            dp[i][j]=-1e18;
        }
    }

    int n,W,B,X;
    cin>>n>>W>>B>>X;
    for (int i=1;i<=n;i++){
        cin>>c[i];
        pref[i]=pref[i-1]+c[i];
    }
    for (int i=1;i<=n;i++){
        cin>>cost[i];
    }

    dp[0][0]=W;
    for (int i=0;i<n;i++){
        for (int j=0;j<=pref[i];j++){
            if (dp[i][j]>=0){
                ll cur_have=dp[i][j];
                ll max_have=W+1ll*j*B;
                maximize(dp[i+1][j],min(max_have,cur_have+X));
                for (int k=1;k<=c[i+1];k++){
                    if (cur_have<cost[i+1]){
                        break;
                    }
                    cur_have-=cost[i+1];
                    max_have+=B;
                    maximize(dp[i+1][j+k],min(max_have,cur_have+X));
                }
            }
        }
    }
    int ans=0;
    for (int i=0;i<=pref[n];i++){
        if (dp[n][i]>=0){
            ans=i;
        }
    }
    cout<<ans<<"\n";
}