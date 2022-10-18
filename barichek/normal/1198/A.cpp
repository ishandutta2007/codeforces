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

    fast;

    int n,i;
    cin>>n>>i;
    i*=8;
    map<int,int> cnt;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        cnt[a]++;
    }
    vector<pii> a(all(cnt));
    int ans=1e9;
    int can=i/n;
    if (can>60){
        can=1e9;
    }
    else{
        can=(1ll<<can);
    }

    vector<int> pref(n,0);
    for (int i=0;i<len(a);i++){
        if (i){
            pref[i]+=pref[i-1];
        }
        pref[i]+=a[i].sec;
    }

//    cout<<can<<" !!!\n";

    for (int i=0;i<len(a);i++){
        int cur=0;
        cur+=n-pref[i];
        int l=i-can+1;
//        cout<<i<<" "<<l<<"\n";
        if (l<0){
            l=0;
        }
        cur+=(l>0?pref[l-1]:0);
        ans=min(ans,cur);
    }
    cout<<ans<<"\n";
}