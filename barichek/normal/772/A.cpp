#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) name!=""?freopen(name".in","r",stdin),freopen(name".out","w",stdout):0
#define files_ds(name) name!=""?freopen(name".dat","r",stdin),freopen(name".sol","w",stdout):0
#define all(a) a.begin(),a.end()
#define len(a) (int)(a.size())
#define elif else if
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

#ifdef I_love_Maria_Ivanova
    #define debug if (1)
#else
    #define debug if (0)
#endif

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

int n,p;
vector<pii> v;

bool check(ld x)
{
    ld cnt_gavno=0;
    for (auto i:v){
        ld val=i.sec-x*i.fir;
        if (val<0){
            cnt_gavno+=abs(val)/ld(p);
        }
    }
    return cnt_gavno+eps<=x;
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #else
        files("");
        files_ds("");
    #endif

    fast;
    cin>>n>>p;
    v.resize(n);
    for (auto& i:v){
        cin>>i.fir>>i.sec;
    }
    ld l=0,r=1e15;
    if (check(r)){
        return cout<<-1, 0;
    }
    for (int oper=0;oper<500;oper++){
        ld m=(l+r)/2.0;
        if (check(m)){
            l=m;
        }
        else{
            r=m;
        }
    }
    cout<<fixed<<setprecision(10)<<r;
}