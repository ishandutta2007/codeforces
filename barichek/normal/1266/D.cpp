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

int val[arr];

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    int n,m;
    cin>>n>>m;
    while (m--){
        int u,v,d;
        cin>>u>>v>>d;
        val[u]-=d;
        val[v]+=d;
    }
    set<pii> keks;
    for (int i=1;i<=n;i++){
        keks.insert(mp(val[i],i));
    }
    vector<pair<pii,int>> ans(0);
    while (!keks.empty()&&keks.begin()->fir<0){
        int u=keks.begin()->sec;
        int v=keks.rbegin()->sec;
        keks.erase(mp(val[u],u));
        keks.erase(mp(val[v],v));
        int cur=min(abs(val[u]),abs(val[v]));
        ans.pb(mp(mp(u,v),cur));
        val[u]+=cur;
        val[v]-=cur;
        keks.insert(mp(val[u],u));
        keks.insert(mp(val[v],v));
    }
    cout<<len(ans)<<"\n";
    for (auto i:ans){
        cout<<i.fir.fir<<" "<<i.fir.sec<<" "<<i.sec<<"\n";
    }
}