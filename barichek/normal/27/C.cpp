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

#define arr(int)(1e6+10)

pii pref_min[arr];
pii pref_max[arr];

pii suf_min[arr];
pii suf_max[arr];

int a[arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }

    pref_min[0]={1e9,-1};
    pref_max[0]={-1e9,-1};
    for (int i=1;i<=n;i++){
        pref_min[i]=min(pref_min[i-1],{a[i],i});
        pref_max[i]=max(pref_max[i-1],{a[i],i});
    }
    suf_min[n+1]={1e9,-1};
    suf_max[n+1]={-1e9,-1};
    for (int i=n;i>=1;i--){
        suf_min[i]=min(suf_min[i+1],{a[i],i});
        suf_max[i]=max(suf_max[i+1],{a[i],i});
    }

    for (int i=1;i<=n;i++){
        if (pref_min[i-1].fir<a[i]&&suf_min[i+1].fir<a[i]){
            cout<<3<<"\n";
            cout<<pref_min[i-1].sec<<" "<<i<<" "<<suf_min[i+1].sec<<"\n";
            return 0;
        }
        if (pref_max[i-1].fir>a[i]&&suf_max[i+1].fir>a[i]){
            cout<<3<<"\n";
            cout<<pref_max[i-1].sec<<" "<<i<<" "<<suf_max[i+1].sec<<"\n";
            return 0;
        }
    }

    cout<<0<<"\n";
}