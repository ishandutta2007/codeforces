#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
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
typedef vector<pll> vpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
ll mod = 1000000007;

typedef unsigned int uint;
template<class C> void mini(C&a, C b){a=min(a,b);}
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
#define F first
#define S second
#define INF 1e9
#define todo(v) v.begin(),v.end()
#define eps 0.000000001

void a(){
    ll x,y;
    cin>>x>>y;
    if(x == y+1) cout<<"NO\n";
    else cout<<"YES\n";
}

void sacarRepetidos(vi& v){
    vi res;
    res.pb(v[0]);
    F1(i,v.size()-1){
        if(v[i] != v[i-1]) res.pb(v[i]);
    }
    v = res;
}

void b(){
    int n,r;
    cin>>n>>r;
    vi mon(n);
    F0(i,n) cin>>mon[i];
    sort(todo(mon));
    sacarRepetidos(mon);
    int res = 0;
    F0R(i,mon.size()){
        if(mon[i] <= r * res) break;
        res++;
    }
    cout<<res<<'\n';
}

void c(){
    int h,n;
    cin>>h>>n;
    vi x(n);
    F0(i,n) cin>>x[i];
    int res = 0;

    int altura = h;
    F0(i,n-1){
        if(x[i] <= 2) break;
        if(x[i] == x[i+1]+1 and i+2 < n and x[i] == x[i+2]+2) i++;
        else if(x[i] == x[i+1]+1) {
            x[i+1] = x[i] - 2;
            res++;
        }
        else {
            x[i] = x[i+1]+1;
            i--;
        }
    }
    cout<<res<<'\n';
}

int main(){
    int t;
    cin>>t;
    while(t--) c();
}