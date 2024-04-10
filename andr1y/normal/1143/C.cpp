#include <bits/stdc++.h>
#define ld long double
#define ll long long
#define ull unsigned ll
#define pll pair<ll, ll>
#define itr(a) begin(a), end(a)
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define pp(a, b) pb(mp(a, b))
#define get_bit(n, k) n&(1<<k)
#define endl '\n'
#define vl vector<ll>
#define PI 3.1415926535897932384626433832795
#define rad(deg) deg*PI/180
#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout);
#define M 1000000007
#define N 100001
#define INF LLONG_MAX
#define NINF -INF-1
#define PAIR_OUT_PRE "("
#define PAIR_OUT_BTW ";"
#define PAIR_OUT_PST "), "
#define ARRAY_OUT_PRE "data: "
#define ARRAY_OUT_BTW ", "
#define ARRAY_OUT_PST endl
using namespace std;
template<typename T, typename D> ostream& operator<<(ostream& os, const pair<T, D> V){return os << PAIR_OUT_PRE << V.x << PAIR_OUT_BTW << V.y << PAIR_OUT_PST;}
template<typename T> ostream& operator<<(ostream& os, const vector<T> V){os << ARRAY_OUT_PRE; for(auto i:V)os << i << ARRAY_OUT_BTW; return os << ARRAY_OUT_PST;}
template<typename T, size_t S> ostream& operator<<(ostream& os, const array<T, S> V){os << ARRAY_OUT_PRE; for(auto i:V)os << i << ARRAY_OUT_BTW; return os << ARRAY_OUT_PST;}
/*--func--*/
template<typename T> ull fast_log(T a){ull c = 0;while((a>>(++c)) > 0);return c-1;}
vector<ll> d[N];
ll x[N];
ll pd[N];
ll p[N];
void dfs(ll v, ll p = -1){
    pd[v] = x[v];
    for(auto i : d[v]){
        if(i==p) continue;
        dfs(i, v);
        pd[v]+=pd[i];
    }
}
main(){
    FAST;
    ll n, px, c, root;
    cin >> n;
    for(ll i=1;i<=n;i++){
        cin >> px >> c;
        if(px==-1) root = i;
        else d[px].pb(i);
        p[i] = px;
        x[i] = 1 - c;
    }
    dfs(root);
    set<ll> q;
    for(ll i=1;i<=n;i++){
        if(x[i]==1 || i == root) continue;
        ll c1c = 0;
        for(auto j : d[i]) if(j != p[i] && x[j] == 1) c1c++;
        if(c1c>0) continue;
        else{
            q.insert(i);
        }
    }
    if(q.size()==0) cout << -1;
    else for(auto i : q) cout << i << " ";
}