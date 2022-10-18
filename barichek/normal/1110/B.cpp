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

pii dp[arr];
int n,m,k;
int b[arr];

//pii get(int x)
//{
//    for (int i=1;i<=n;i++){
//        dp[i]=mp(2e18,2e18);
//    }
//    dp[0]=mp(0,0);
//    pii best=mp(0,0);
//}

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

//    cin>>n>>m>>k;
//    for (int i=1;i<=n;i++){
//        cin>>b[i];
//    }
//    int l=0,r=2e9;
//    while (r-l>0){
//        int m=(l+r)/2;
//        auto g=get(m);
//        if (g.second>k){
//            l=m+1;
//        }
//        else{
//            r=m;
//        }
//    }
//    auto g=get(l);
//    cout<<g.fir-l*k<<"\n";


    cin>>n>>m>>k;
    for (int i=1;i<=n;i++){
        cin>>b[i];
    }
    vector<int> v(0);
    for (int i=2;i<=n;i++){
        v.pb(b[i]-b[i-1]);
    }
    sort(all(v));
    int ans=n;
    int del=n-k;
    for (int i=0;i<del;i++){
        ans+=v[i]-1;
    }
    cout<<ans<<"\n";
}