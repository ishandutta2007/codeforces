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

int n,m;
int a[10*arr];
int b[10*arr];

bool check(int x)
{
    b[0]=a[0];
    if (a[0]+x>=m){
        b[0]=0;
    }
    for (int i=1;i<n;i++){
        b[i]=a[i];
        if (b[i]<b[i-1]&&b[i]+x<b[i-1]){
            return 0;
        }
        if (b[i]<b[i-1]){
            b[i]=b[i-1];
        }
        elif (b[i]+x>=m&&b[i]+x-m>=b[i-1]){
            b[i]=b[i-1];
        }
    }
    return 1;
}

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    cin>>n>>m;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    int l=0,r=m;
    while (r-l>0){
        int m=(l+r)/2;
        if (check(m)){
            r=m;
        }
        else{
            l=m+1;
        }
    }
    cout<<l<<"\n";
}