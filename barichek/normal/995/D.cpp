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

int a[10000000];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    int n,r;
    cin>>n>>r;
    int sum=0;
    n=(1ll<<n);
    for (int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    cout<<fixed<<setprecision(10)<<ld(sum)/n<<"\n";
    while (r--){
        int p,x;
        cin>>p>>x;
        sum-=a[p];
        a[p]=x;
        sum+=a[p];
        cout<<fixed<<setprecision(10)<<ld(sum)/n<<"\n";
    }
}