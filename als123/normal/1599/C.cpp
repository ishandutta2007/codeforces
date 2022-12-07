#include <bits/stdc++.h>

#define lyons ;
#define fulcrum(...) ;
#ifndef promising
#define dump(...)
#endif

#define E 2.718281828459045
#define PI 3.141592653589793
#define M1 167772161
#define M3 998244353
#define M7 1000000007
#define INF 0x3fffffff
#define INF64 0x3fffffff3fffffff

const int P=M3;

#define loop(i,n) for(int i=0;i<(n);i++)
#define lback(i,n) for(int i=(n)-1;i>=0;i--)
#define rep(i,l,r) for(int i=(l);i<(r);i++)
#define rback(i,l,r) for(int i=(r)-1;i>=(l);i--)
#define all(x) (x).begin(),(x).end()
#define isz(x) ((int)(x).size())
#define iln(x) ((int)(x).length())
#define rank(x) sort(x),reverse(x)

#define mid (l+(r-l)/2)
#define lson (x<<1)
#define rson (x<<1|1)

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,int> pli;
typedef pair<long long,long long> pll;
typedef complex<double> cp;
template<class T> using vector2D = vector<vector<T>>;
template<class T> using vector3D = vector<vector2D<T>>;
template<class T> using pque = priority_queue<T>;
template<class T> using heap = priority_queue<T,vector<T>,greater<T>>;

template<class T> T max(T a, T b, T c) { return max(max(a,b),c); }
template<class T> T min(T a, T b, T c) { return min(min(a,b),c); }
template<class T> bool umax(T &x, T y) { return (x<y)? x=y,true: false; }
template<class T> bool umin(T &x, T y) { return (x>y)? x=y,true: false; }

void prepare() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

ll n;
double p,i3=1.0/3;
const double eps=1e-10;
double calc(ll m) {
    ll k=n-m;
    ll tot=n*(n-1)*(n-2)/6;
    ll cas0=k*(k-1)*(k-2)/6;
    ll cas1=k*(k-1)/2*m;
    ll cas2=m*(m-1)/2*k;
    ll cas3=m*(m-1)*(m-2)/6;
    return (double)(cas3+cas2)/tot+0.5*cas1/tot;
}


int main() {
    prepare();
    cin>>n>>p;
    int l=0,r=n,ans=-1;
    while(l<=r) {
        if(calc(mid)<p-eps) l=mid+1;
        else ans=mid,r=mid-1;
    }
    cout<<ans<<endl;
    return 0;
}