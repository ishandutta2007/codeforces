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

bool check(int m,int n,int want)
{
//    cerr<<"check"<<" :: "<<m<<"\n";
    int ans=0;
    while (n){
//        cerr<<n<<" !!!\n";
        int cur=min(n,m);
        ans+=cur;
        n-=cur;
        n-=n/10;
    }
    return ans>=want;
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n;
    cin>>n;
    int want=n/2+n%2;
    int l=1,r=1e18;
    while (r-l>0){
        int m=(l+r)/2;
        if (check(m,n,want)){
            r=m;
        }
        else{
            l=m+1;
        }
    }
    cout<<l<<"\n";
}