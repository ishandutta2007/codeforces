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

int prec[arr];

void precalc(int a,int id)
{
    int res=1;
    for (int i=1;i*i<=a;i++){
        if (a%i==0){
            if (i!=a){
                res=max(res,__gcd(i,a-i));
            }
            if (i!=1){
                res=max(res,__gcd(a/i,a-a/i));
            }
        }
    }
    prec[id]=res;
}

void solve()
{
    int a;
    cin>>a;
    int cnt_1=__builtin_popcountll(a);
    int last_1=-1;
    for (int i=0;i<30;i++){
        if (a&(1ll<<i)){
            last_1=i;
        }
    }
    if (last_1+1==cnt_1){
        cout<<prec[cnt_1]<<"\n";
    }
    else{
        cout<<(1ll<<(last_1+1))-1<<"\n";
    }
}

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    for (int i=2;i<=25;i++){
        precalc((1ll<<i)-1,i);
    }
    int test;
    cin>>test;
    while (test--){
        solve();
    }
}