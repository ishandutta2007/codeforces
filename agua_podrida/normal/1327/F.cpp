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
#define INF 1e9
#define todo(v) v.begin(),v.end()
#define eps 0.000000001
#define PI acos(-1.0)
const ll mod = 998244353;

int n,k,m;
int l,r,x;

vi b;
vll dp;
vvpi c;

ll g(vector<tuple<int,int,int>>& a, int bit){
    F0(i,n+2) b[i] = 0;
    F0(i,n+1) dp[i] = 0;
    for(auto t : a){
        tie(l,r,x) = t;
        if(x & (1<<bit)) b[l]++, b[r]--;
    }
    F1(i,n+1) b[i] += b[i-1];

    int j = 0;
    ll suma = 1;
    dp[0] = 1;
    int i = 1;
    while(i <= n+1){
        for(auto t : c[i]){
            tie(l,x) = t;
            if(x & (1<<bit)) continue;
            while(j < l){
                suma -= dp[j];
                suma %= mod;
                j++;
            }
        }

        if(i == n+1) break;

        if(b[i] == 0) dp[i] = suma;
        suma += dp[i];
        suma %= mod;
        i++;
    }
    return suma;
}

void f(){
    cin>>n>>k>>m;
    b.resize(n+2);
    dp.resize(n+1);
    c.resize(n+2);
    vector<tuple<int,int,int>> a;
    F0(i,m){
        cin>>l>>r>>x;
        r++;
        a.pb({l,r,x});
        c[r].pb({l,x});
    }
    ll res = 1;
    F0(i,k) res *= g(a,i), res %= mod;
    if(res < 0) res += mod;
    cout<<res<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    f();
}