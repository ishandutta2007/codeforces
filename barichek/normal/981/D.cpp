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

int n,k;
int a[arr];
bool dp[51][51]; /// [pref][block]

bool can(int mask)
{
    for (int i=0;i<=50;i++){
        for (int j=0;j<=50;j++){
            dp[i][j]=0;
        }
    }
    dp[0][0]=1;
    for (int i=0;i<n;i++){
        for (int j=0;j<k;j++){
            if (dp[i][j]){
                int cur=0;
                for (int t=i+1;t<=n;t++){
                    cur+=a[t];
                    if ((cur&mask)==mask){
                        dp[t][j+1]=1;
                    }
                }
            }
        }
    }
    return dp[n][k];
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    cin>>n>>k;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans=0;
    for (int i=60;i>=0;i--){
        if (can(ans+(1ll<<i))){
            ans+=(1ll<<i);
        }
    }
    cout<<ans<<"\n";
}