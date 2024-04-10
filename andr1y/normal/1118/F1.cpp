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
#define N 300000
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
ll real_color[N];
ll pcount[2][N];
ll acount[2];
ll good = 0, n, a, b;
void dfs(ll v = 1, ll p = -1){
    for(auto i : d[v])
        if(i!=p) dfs(i, v);
    for(auto i : d[v])
        if(i!=p) pcount[0][v]+=pcount[0][i], pcount[1][v]+=pcount[1][i];
    if(real_color[v] != 0) pcount[real_color[v]-1][v]++;
    if((pcount[0][v] == acount[0] && pcount[1][v] == 0) || (pcount[1][v] == acount[1] && pcount[0][v] == 0)) good++;
}
main(){
    FAST;
    cin >> n;
    for(ll i = 1;i<=n;i++){
        cin >> real_color[i];
        if(real_color[i] != 0) acount[real_color[i]-1]++;
    }
    for(ll i = 1;i<n;i++){
        cin >> a >> b;
        d[a].pb(b);
        d[b].pb(a);
    }
    dfs();
    cout << good << endl;
}