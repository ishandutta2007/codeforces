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

int get(int l,int r,int a)
{
    return r/a-(l-1)/a;
}

bool check(int la,int ra,int ta,int lb,int rb,int tb,int x)
{
    if (x==0){
        return 1;
    }
    x--;
    int L1=lb-la;
    int R1=rb-la-x;
    int g=__gcd(ta,tb);
//    cout<<x<<" !!!\n";
//    cout<<L1<<" "<<R1<<" "<<g<<"\n";
    if (L1<=0){
        int kek=abs(L1/g)+10;
        L1+=kek*g;
        R1+=kek*g;
    }

//    cout<<x<<" !\n";
//    cout<<L1<<" "<<R1<<" "<<g<<"\n";
    if (get(L1,R1,g)!=0){
        return 1;
    }
    else{
        return 0;
    }
}

int solve(int la,int ra,int ta,int lb,int rb,int tb)
{
    int l=0,r=min(ra-la+1,rb-lb+1);
    while (r-l>0){
        int m=(l+r+1)/2;
        if (check(la,ra,ta,lb,rb,tb,m)){
            l=m;
        }
        else{
            r=m-1;
        }
    }
    return l;
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int la,ra,ta;
    cin>>la>>ra>>ta;
    int lb,rb,tb;
    cin>>lb>>rb>>tb;
    int ans=0;
    ans=max(ans,solve(la,ra,ta,lb,rb,tb));
    ans=max(ans,solve(lb,rb,tb,la,ra,ta));
    cout<<ans<<"\n";
}