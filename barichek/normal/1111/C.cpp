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

int a[arr];
int n,k,A,B;

int f(int l,int r,int L,int R) /// [l;r)
{
//    cout<<"here :: "<<l<<" "<<r<<" || "<<L<<" "<<R<<"\n";
    if (l==r){
        return A;
    }
    if (L==R){
        return B*(r-l);
    }
    int M=(L+R)/2;
    int id=upper_bound(a+l,a+r,M)-a;
    int VL=f(l,id,L,M)+f(id,r,M+1,R);
    int VR=B*(R-L+1)*(r-l);
//    cout<<L<<" "<<R<<" :: "<<VL<<" "<<VR<<"\n";
    return min(VL,VR);
}

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    cin>>n>>k>>A>>B;
    for (int i=0;i<k;i++){
        cin>>a[i];
    }
    sort(a,a+k);
    cout<<f(0,k,1,(1ll<<n))<<"\n";
}