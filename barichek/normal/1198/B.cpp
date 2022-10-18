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

int ans[arr];

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    int n;
    cin>>n;
    vector<pii> vec(0);
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        vec.pb(mp(i,a));
    }
    int q;
    cin>>q;
    for (int i=0;i<q;i++){
        int type;
        cin>>type;
        if (type==1){
            int p,x;
            cin>>p>>x;
            p--;
            vec.pb(mp(p,x));
        }
        else{
            int x;
            cin>>x;
            vec.pb(mp(-1,x));
        }
    }
    int mx=-2e9;
    reverse(all(vec));
    for (int i=0;i<n;i++){
        ans[i]=-2e9;
    }
    for (auto i:vec){
        if (i.fir==-1){
            mx=max(mx,i.sec);
        }
        else{
            if (ans[i.fir]!=-2e9){
                continue;
            }
            ans[i.fir]=max(mx,i.sec);
        }
    }
    for (int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}