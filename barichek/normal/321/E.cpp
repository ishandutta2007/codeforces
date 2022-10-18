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

pii operator+(pii a,pii b)
{
    return mp(a.fir+b.fir,a.sec+b.sec);
}

int n,k;
int cnt[4011][4011];
int a[4011][4011];
int sum[4011][4011];

pii dp[4001];

pii get(int x)
{
    dp[0]={0,0};
    for (int i=1;i<=n;i++){
        dp[i]=mp(1e9,1e9);
    }
    for (int i=0;i<=n;i++){
        for (int j=i+1;j<=n;j++){
            dp[j]=min(dp[j],dp[i]+mp(cnt[i+1][j]+x,1ll));
        }
    }
    return dp[n];
}

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    cin>>n>>k;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            char c;
            cin>>c;
            a[i][j]=c-'0';
            sum[i][j]=sum[i][j-1]+a[i][j];
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=i;j<=n;j++){
            cnt[i][j]=cnt[i][j-1]+sum[j][j-1]-sum[j][i-1];
        }
    }

    int l=0,r=1e8;
    while (r-l>0){
        int m=(l+r)/2;
        if (get(m).second>k){
            l=m+1;
        }
        else{
            r=m;
        }
    }

//    cout<<l<<" !!\n";

    cout<<get(l).first-k*l<<"\n";
}