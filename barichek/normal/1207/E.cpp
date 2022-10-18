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

///---program start---///

main()
{
//    #ifdef Barik
//        files("barik");
//        freopen("debug.txt","w",stderr);
//    #endif

    int ans=0;

    cout<<"?"<<" ";
    for (int i=1;i<=100;i++){
        cout<<i<<" ";
    }
    cout<<"\n";
    fflush(stdout);
    int res1;
    cin>>res1;
    ans^=((res1>>7)<<7);

    cout<<"?"<<" ";
    for (int i=1;i<=100;i++){
        int cur_req=0;
        for (int j=0;j<7;j++){
            if (i&(1ll<<j)){
                cur_req|=(1ll<<(13-j));
            }
        }
        cout<<cur_req<<" ";
    }
    cout<<"\n";
    fflush(stdout);
    int res2;
    cin>>res2;
    ans^=(res2&((1ll<<7)-1));

    cout<<"!"<<" "<<ans<<"\n";
}