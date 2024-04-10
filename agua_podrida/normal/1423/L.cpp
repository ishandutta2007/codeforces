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
#define forall(it,s) for(auto it : s)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define INF 1e18
#define forn(i,n) for(int i=0; i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(int) s; i<(int)(n); i++)
#define todo(v) v.begin(),v.end()
#define eps 0.000000001
#define PI acos(-1.0)
#define fora(e,v) for(auto e : v)
#define sq(a) (a)*(a)
#define teamSize(t) ((t)<t4 ? 4 : ( (t)<t4+t3 ) ? 3 : 2 )
#define R real
#define I imag
const ll mod = 1e9+7;

ll myrand(){
    ll res = 0;
    F0(i,62) if(rand()%2) res += (1ll<<i);
    return res;
}

void a(){
    int n,s,d;
    cin>>n>>s>>d;
    vll h(n+1);
    F1(i,n) h[i] = myrand();
    int izq = 0;
    int der = s;
    while(izq*2 < der) izq++, der--;
    vll S1(izq),S2(der);
    int c,x;
    F0(i,izq){
        cin>>c;
        while(c--){
            cin>>x;
            S1[i] ^= h[x];
        }
    }
    F0(i,der){
        cin>>c;
        while(c--){
            cin>>x;
            S2[i] ^= h[x];
        }
    }

    unordered_map<ll,int> dp1,dp2;

    F0(mask,(1<<izq)){
        ll hash = 0;
        F0(i,izq) {
            if(mask & (1<<i)) hash ^= S1[i];
        }
        if(!dp1.count(hash)) dp1[hash] = __builtin_popcount(mask);
        else mini(dp1[hash],__builtin_popcount(mask));
    }
    F0(mask,(1<<der)){
        ll hash = 0;
        F0(i,der) {
            if(mask & (1<<i)) hash ^= S2[i];
        }
        if(!dp2.count(hash)) dp2[hash] = __builtin_popcount(mask);
        else mini(dp2[hash],__builtin_popcount(mask));
    }

    while(d--){
        cin>>c;
        ll hash = 0;
        while(c--){
            cin>>x;
            hash ^= h[x];
        }
        int res = s+1;
        for(auto it : dp1){
            if(dp2.count(hash^it.first)) mini(res,it.second + dp2[hash^it.first]);
        }
        if(res == s+1) res = -1;
        cout<<res<<'\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    a();
}