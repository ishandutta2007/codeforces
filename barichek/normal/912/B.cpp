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

vector<pii> vh[arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int k,n;
    cin>>n>>k;
    if (k==1){
        return cout<<n<<"\n", 0;
    }
    else{
        int ans=0;
        for (int i=62;i>=0;i--){
            if ((1ll<<i)<=n){
                ans+=(1ll<<i);
            }
        }
        cout<<ans<<"\n";
    }

//    fast;
//    int n,m;
//    cin>>n>>m;
//    int bounty,increase,damage;
//    cin>>bounty>>increase>>damage;
//    vector<pair<pii,int>> a(n);
//    for (auto& i:a){
//        cin>>i.fir.fir>>i.fir.sec>>i.sec;
//    }
//    vector<pair<pii,int>> b(m);
//    for (auto& i:b){
//        cin>>i.fir.fir>>i.fir.sec>>i.sec;
//        i.fir.sec--;
//        vh[i.fir.sec].pb({i.fir.fir,i.sec});
//    }
//    if (increase==0){
//        vector<pii> q(0);
//        for (int i=0;i<n;i++){
//            if (a[i].fir.fir<=damage)
//            sort(all(vh[i]));
//            int r=-1;
//            if (a[i].fir.sec<=damage){
//            }
//        }
//    }
//    else{
//
//    }
}