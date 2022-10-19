#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
using ll = long long;
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
#define forall(it,s) for(auto it = s.begin(); it != s.end();it++)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define forn(i,n) for(int i=0; i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(int) s; i<(int)(n); i++)
#define todo(v) v.begin(),v.end()
#define PI acos(-1.0)
#define fora(e,v) for(auto e : v)
const int mod = 1e9+7;
const ll INF  = 1e18;
const double eps = 0.00000001;

int n,k;

void E(){
    cin>>n>>k;
    vi a(n*k+1);
    F1(i,n*k) cin>>a[i];
    vi ult(n+1);
    vpi res(n+1);
    int terminaron = 0;
    int i = 1;
    while(i <= n*k){
        if(ult[a[i]] == 0) ult[a[i]] = i;
        else if(ult[a[i]] > 0) {
            res[a[i]] = {ult[a[i]],i};
            ult[a[i]] = -1;
            terminaron++;
        }
        if(terminaron >= (n+k-2) / (k-1)) {
            terminaron = 0;
            F1(j,n) mini(ult[j],0);
        }
        i++;
    }
    F1(i,n){
        cout<<res[i].first<<' '<<res[i].second<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    E();
    return 0;
}