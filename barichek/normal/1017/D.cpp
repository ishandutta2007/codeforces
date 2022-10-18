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

ll dp[101][1ll<<13];
int cnt[1ll<<13];
int w[arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    int n,m,q;
    cin>>n>>m>>q;
    for (int i=1;i<=n;i++){
        cin>>w[i];
    }
    for (int i=0;i<m;i++){
        int a=0;
        for (int j=0;j<n;j++){
            char s;
            cin>>s;
            if (s=='1'){
                a+=(1ll<<j);
            }
        }
        cnt[a]++;
    }
    for (int m=0;m<(1ll<<n);m++){
        int val=0;
        for (int i=0;i<n;i++){
            if (!(m&(1ll<<i))){
                val+=w[i+1];
            }
        }
        if (val>100){
            continue;
        }
        for (int a=0;a<(1ll<<n);a++){
            dp[val][a^m]+=cnt[a];
//            cout<<val<<" "<<(a^m)<<" "<<cnt[a]<<"\n";
        }
    }
    while (q--){
        int k;
        int req=0;
        for (int j=0;j<n;j++){
            char s;
            cin>>s;
            if (s=='1'){
                req+=(1ll<<j);
            }
        }
        cin>>k;
//        cout<<"req :: "<<req<<"\n";
        int ans=0;
        for (int j=0;j<=k;j++){
            ans+=dp[j][req];
        }
        cout<<ans<<"\n";
    }
}