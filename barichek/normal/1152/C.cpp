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

int lcm(int a,int b)
{
    return a/__gcd(a,b)*b;
}

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int a,b;
    cin>>a>>b;
    if (a>b){
        swap(a,b);
    }
    if (a==b){
        cout<<0<<"\n";
        return 0;
    }
    int g=b-a;
    int ans=-1;
    int val_ans=-2;

    auto make=[&](int G)
    {
        int cur_os=a%G;
        int K=0;
        if (cur_os){
            K=G-cur_os;
        }
        if (ans==-1||val_ans>lcm(a+K,b+K)||(val_ans==lcm(a+K,b+K)&&ans>K)){
            ans=K;
            val_ans=lcm(a+K,b+K);
        }
    };

    for (int i=1;i*i<=g;i++){
        if (g%i==0){
            make(i);
            make(g/i);
        }
    }

    cout<<ans<<"\n";
}