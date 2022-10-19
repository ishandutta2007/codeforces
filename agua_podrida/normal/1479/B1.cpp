#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
typedef vector<vvpi> vvvpi;
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef complex<double> cd;
typedef vector<cd> vcd;

typedef unsigned int uint;

template<class C> void mini(C&a, C b){ a=min(a, b);}
template<class C> void maxi(C&a, C b){a=max(a,b);}
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define forall(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define INF 2e9
#define todo(v) v.begin(),v.end()
#define eps 0.000000001
#define PI acos(-1.0)
#define mod 1000000007

int seg(vi& a){
    int res = 0;
    if(!a.empty()) res++;
    F1(i,(int) a.size()-1){
        if(a[i] != a[i-1]) res++;
    }
    return res;
}

void b(){
    int n;
    cin>>n;
    vi a(n);
    F0(i,n) cin>>a[i];

    vi b,c;
    F0(i,n){
        if(!b.empty() and b.back() == a[i]) c.pb(a[i]);
        else if(!c.empty() and c.back() == a[i]) b.pb(a[i]);
        else {
            if(b.empty()) c.pb(a[i]);
            else if(c.empty()) b.pb(a[i]);
            else if(i+1 < n){
                if(b.back() == a[i+1]) b.pb(a[i]);
                else c.pb(a[i]);
            }
            else b.pb(a[i]);
        }
    }

    int res = seg(b) + seg(c);
    cout<<res<<'\n';
}

int main(){
    b();
}