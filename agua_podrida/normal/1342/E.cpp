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
typedef vector<vpi> vvpi;
typedef vector<pll> vpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;

typedef unsigned int uint;
template<class C> void mini(C&a, C b){a=min(a,b);}
template<class C> void maxi(C&a, C b){a=max(a,b);}
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define forall(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(ll i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define F first
#define S second
#define INF 1e17
#define todo(v) v.begin(),v.end()
#define eps 0.000000000001
#define mod 998244353

ll pot(ll a, int exp){
    if(exp == 0) return 1;
    ll b = pot(a,exp/2);
    b *= b;
    b %= mod;
    if(exp % 2 == 1) b *= a;
    b %= mod;
    return b;
}

ll inv(ll a){
    return pot(a,mod-2);
}

const int N = 200005;
ll fact[N];

ll calcularFact(){
    fact[0] = 1;
    F1(i,N-1) fact[i] = (fact[i-1]*(ll)i)%mod;
}

ll comb(int n, int k){
    ll c = fact[n];
    c *= inv(fact[k]);
    c %= mod;
    c *= inv(fact[n-k]);
    c %= mod;
    return c;
}

void e(){
    int n,k;
    cin>>n>>k;
    calcularFact();
    if(k == 0){
        cout<<fact[n]<<'\n';
        return;
    }
    if(k >= n){
        cout<<0<<'\n';
        return;
    }
    int c = n-k;
    ll uno = 1;
    ll res = 0;
    F0(i,c) {
        res += uno*pot(c-i,n)*comb(c,i);
        res %= mod;
        res += mod;
        res %= mod;
        uno = -uno;
    }
    res *= comb(n,c);
    res %= mod;
    res *= 2;
    res %= mod;
    cout<<res<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("../output.txt","w",stdout);
    e();
    return 0;
}