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

int a[arr];
int b[arr];
vi vh[arr];

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    int n,k;
    cin>>n>>k;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    for (int i=1;i<=n;i++){
        cin>>b[i];
    }
    for (int i=1;i<=n;i++){
        vh[a[i]].pb(b[i]);
    }
    for (int i=1;i<=k;i++){
        sort(all(vh[i]));
    }

    vi kek(0);
    int lol=0;
    for (int i=1;i<=k;i++){
        if (vh[i].empty()){
            lol++;
        }
        else{
            for (int j=0;j<len(vh[i])-1;j++){
                kek.pb(vh[i][j]);
            }
        }
    }

    int ans=0;
    sort(all(kek));
    for (int i=0;i<lol;i++){
        ans+=kek[i];
//        cout<<kek[i]<<"\n";
    }
    cout<<ans<<"\n";
}