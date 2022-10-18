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

void print(int a,int b)
{
    cout<<0<<" "<<0<<"\n";
    cout<<a<<" "<<0<<"\n";
    cout<<0<<" "<<b<<"\n";
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n,m,k;
    cin>>n>>m>>k;
    int nn=n;
    int mm=m;
    if (2*n*m%k!=0){
        cout<<"NO"<<"\n";
        return 0;
    }
    cout<<"YES"<<"\n";
    int g1=__gcd(n,k);
    n/=g1;
    k/=g1;
    int g2=__gcd(m,k);
    m/=g2;
    k/=g2;
    if (k!=1){
        assert(k==2);
    }
    else{
        if (n*2<=nn){
            n*=2;
        }
        else{
            assert(m*2<=mm);
            m*=2;
        }
    }
    print(n,m);
}