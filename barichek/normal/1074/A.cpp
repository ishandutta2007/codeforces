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

map<int,vector<pii>> vh;
map<int,vector<pii>> vh1;

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    int n,m;
    cin>>n>>m;

    vi lol(0);
    for (int i=1;i<=n;i++){
        int a;
        cin>>a;
        lol.pb(a);
    }
    sort(all(lol));

    vi kek(0);
    for (int i=1;i<=m;i++){
        int x1,x2,y;
        cin>>x1>>x2>>y;
        if (x1==1){
            kek.pb(x2);
        }
    }
    sort(all(kek));

    swap(lol,kek);

    const int aa=1e9;
    int ans=len(kek)+(upper_bound(all(lol),aa+1)-lower_bound(all(lol),aa));
    for (int i=0;i<len(kek);i++){
        int cur_ans=i;
        cur_ans+=len(lol)-(upper_bound(all(lol),kek[i]-1)-lol.begin());
//        cout<<kek[i]<<" "<<cur_ans<<"\n";
        ans=min(ans,cur_ans);
    }
    cout<<ans<<"\n";
}