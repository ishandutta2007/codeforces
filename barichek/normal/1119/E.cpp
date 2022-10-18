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

    int n;
    cin>>n;
    vi a(n);
    for (auto& i:a){
        cin>>i;
    }
    vi pref(n);
    pref[0]=a[0];
    for (int i=1;i<n;i++){
        pref[i]=pref[i-1]+a[i];
    }
    int k=0;
    int ans=0;
    for (int i=n-1;i>=0;i--){
        int l=0,r=a[i]/2;
        while (r-l>0){
            int m=(l+r+1)/2;
            if ((i==0?0:pref[i-1])>=max(0ll,k+m-(a[i]-2*m))){
                l=m;
            }
            else{
                r=m-1;
            }
        }
        ans+=min(k+l,a[i]-2*l);
        k=k+l-min(k+l,a[i]-2*l);
    }
    cout<<ans<<"\n";
}