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
    vi s(n);
    for (auto& i:s){
        cin>>i;
    }
    sort(all(s));

    vi diff(0);
    for (int i=1;i<len(s);i++){
        diff.pb(s[i]-s[i-1]);
    }
    diff.pb(2e18);
    sort(all(diff));
    vi pref(len(diff));
    pref[0]=diff[0];
    for (int i=1;i<len(pref);i++){
        pref[i]=pref[i-1]+diff[i];
    }

    auto get=[&](int L)
    {
        int id=lower_bound(all(diff),L)-diff.begin();
        /**

        [0;id) - sum
        [id;len(diff)) - L for each


        */

        int res=0;
        if (id!=0){
            res+=pref[id-1];
        }
        res+=L*(len(diff)-id);
        return res;
    };

    int q;
    cin>>q;
    while (q--){
        int l,r;
        cin>>l>>r;
        cout<<get(r-l+1)<<"\n";
    }
}