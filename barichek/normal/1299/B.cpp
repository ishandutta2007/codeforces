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
const ll inf=1e18+10;

///---program start---///

int x[arr];
int y[arr];

int dist2(int x1,int y1,int x2,int y2)
{
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif
    
    fast;
    
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>x[i]>>y[i];
    }
    if (n%2==1){
        bool ok=1;
        for (int i=0;i<n;i++){
            if (x[(i)%n]-x[(i-1+n)%n]!=x[(i+1)%n]-x[(i)%n]){
                ok=0;
            }
        }
        for (int i=0;i<n;i++){
            swap(x[i],y[i]);
        }
        for (int i=0;i<n;i++){
            if (x[(i)%n]-x[(i-1+n)%n]!=x[(i+1)%n]-x[(i)%n]){
                ok=0;
            }
        }
        cout<<(ok?"YES":"NO")<<"\n";
        return 0;
    }
    else{
        bool ok=1;
        for (int i=0;i<n;i++){
            if (x[(i)%n]-x[(i-1+n)%n]!=-1*(x[(i+n/2)%n]-x[(i-1+n+n/2)%n])){
                ok=0;
            }
        }
        for (int i=0;i<n;i++){
            swap(x[i],y[i]);
        }
        for (int i=0;i<n;i++){
            if (x[(i)%n]-x[(i-1+n)%n]!=-1*(x[(i+n/2)%n]-x[(i-1+n+n/2)%n])){
                ok=0;
            }
        }
        cout<<(ok?"YES":"NO")<<"\n";
        return 0;
    }
}