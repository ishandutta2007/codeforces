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

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    vector<pair<int,int>> v0;
    v0.pb(mp(1,1));
    v0.pb(mp(1,2));
    v0.pb(mp(1,3));
    v0.pb(mp(1,4));

    vector<pair<int,int>> v1;
    v1.pb(mp(3,1));
    v1.pb(mp(3,3));
    v1.pb(mp(4,1));
    v1.pb(mp(4,3));

    string s;
    cin>>s;
    int p0=0;
    int p1=0;
    for (auto i:s){
        if (i=='0'){
            cout<<v0[p0].fir<<" "<<v0[p0].sec<<"\n";
            p0++;
            p0%=4;
        }
        else{
            cout<<v1[p1].fir<<" "<<v1[p1].sec<<"\n";
            p1++;
            p1%=4;
        }
    }
}