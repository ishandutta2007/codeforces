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

int a[arr];
int pref_or[arr];
int suf_or[arr];

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
        pref_or[i]=pref_or[i-1]|a[i];
    }
    for (int i=n;i>=1;i--){
        suf_or[i]=suf_or[i+1]|a[i];
    }
    int best_val=-1;
    int best_pos=0;
    for (int i=1;i<=n;i++){
        int or_not_me=pref_or[i-1]|suf_or[i+1];
        int cur_val = a[i] & (((1ll<<40)-1)^or_not_me);
        if (cur_val>=best_val){
            best_val=cur_val;
            best_pos=i;
        }
    }
    cout<<a[best_pos];
    for (int i=1;i<=n;i++){
        if (i!=best_pos){
            cout<<" "<<a[i];
        }
    }
    cout<<"\n";
}