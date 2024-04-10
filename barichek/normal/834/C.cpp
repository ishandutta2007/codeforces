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

bool check(int a)
{
//    cout<<"check :: "<<a<<"\n";
    int l=1,r=1e6+10;
    while (r-l>1){
        int m=(l+r)/2;
        if (m*m*m>a){
            r=m;
        }
        else{
            l=m;
        }
    }
    return l*l*l==a||r*r*r==a;
}

bool check(int a,int b)
{
    int g=__gcd(a,b);
    int abg=a*b/g;
//    cout<<"g :: "<<g<<" && abg :: "<<abg<<"\n";
    if (g*g%abg!=0){
        return 0;
    }
    return check(g*g/abg);
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
    int n;
    cin>>n;
    while (n--){
        int a,b;
        cin>>a>>b;
        cout<<(check(a,b)?"YES":"NO")<<"\n";
    }
}