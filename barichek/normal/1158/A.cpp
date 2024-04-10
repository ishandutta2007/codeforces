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

const int arr=2e6+10;
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

    int n,m;
    cin>>n>>m;
    vi a(n);
    vi b(m);
    for (auto& i:a){
        cin>>i;
    }
    for (auto& j:b){
        cin>>j;
    }
    sort(all(a));
    sort(all(b));
    if (a.back()>b[0]){
        cout<<-1<<"\n";
        return 0;
    }
    if (n==1&&a.back()!=b[0]){
        cout<<-1<<"\n";
        return 0;
    }
    int ans=0;
    for (auto i:a){
        ans+=i*m;
    }
    if (a.back()==b[0]){
        for (auto j:b){
            ans+=j-a.back();
        }
    }
    else{
        for (auto j:b){
            ans+=j-a.back();
        }
        ans+=a.back();
        ans-=a[len(a)-2];
    }
    cout<<ans<<"\n";
}