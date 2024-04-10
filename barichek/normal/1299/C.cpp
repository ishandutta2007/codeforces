//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
//#pragma GCC optimize("unroll-loops")
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
const ll inf=1e18+10;

///---program start---///

#define arr (int)(1e6+10)

int a[arr];
int pref[arr];
int best[arr];

ld ans[arr];

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif
    
    fast;
    
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        pref[i]=pref[i-1]+a[i];
    }
    
    auto calc_bests = [&]()
    {
        vector<pii> vec;
        auto better = [&](int xr1,int yr1,int xr2,int yr2,int xl,int yl)
        {
            /// 1 better than 2
            
            /// (yr1-yl)/(xr1-xl)<(yr2-yl)/(xr2-xl)
            return (yr1-yl)*(xr2-xl)<(yr2-yl)*(xr1-xl);
        };
        auto get_best = [&](int x,int y)
        {
            while (len(vec)>1){
                if (better(
                    vec[len(vec)-2].fir,vec[len(vec)-2].sec,
                    vec[len(vec)-1].fir,vec[len(vec)-1].sec,x,y
                )){
                    vec.pop_back();
                }
                else{
                    break;
                }
            }
            auto to_return = vec.back();
            vec.pb(mp(x,y));
            return to_return;
        };
        vec.pb(mp(n,pref[n]));
        for (int i=n-1;i>=0;i--){
            best[i]=get_best(i, pref[i]).fir;
            // cout<<"best["<<i<<"] :: "<<best[i]<<"\n";
        }
    };
    
    calc_bests();
    
    for (int i=1;i<=n;){
        int lol=best[i-1];
        // cout<<i<<" "<<lol<<"\n";
        ld val = ld(pref[lol]-pref[i-1])/(lol-(i-1));
        for (int j=i;j<=lol;j++){
            ans[j]=val;
        }
        i=lol+1;
    }
    for (int i=1;i<=n;i++){
        cout<<fixed<<setprecision(10)<<ans[i]<<"\n";
    }
}