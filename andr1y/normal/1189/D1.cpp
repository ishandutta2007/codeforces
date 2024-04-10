#include <bits/stdc++.h>
#define ld long double
#define ll long long
#define ull unsigned ll
#define pll pair<ll, ll>
#define itr(a) begin(a), end(a)
#define pb push_back
#define x first
#define y second
#define endl '\n'
#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout);
#define M 1000000007
#define N 100001
#define INF 101111111111111
#define NINF -INF-1
#define F(i, n) for(ll i =0;i<n;i++)
using namespace std;
template<typename T, typename D> ostream& operator<<(ostream& os, const pair<T, D> V){return os << "(" << V.x << ";" << V.y << ")";}
template<typename T> ostream& operator<<(ostream& os, const vector<T> V){os << "array: " << endl; for(auto i:V)os << i << " "; return os << endl;}
template<typename T, size_t S> ostream& operator<<(ostream& os, const array<T, S> V){os << "vector: " << endl; for(auto i:V)os << i << " "; return os << endl;}
vector<ll> d[N];
bool ok = true;
void dfs(ll v, ll p = -1, ll last_kids = -1){
    if(d[v].size() == 2){
        ok = false;
        return;
    }
    for(auto i : d[v]){
        if(i!=p) dfs(i, v, d[v].size());
    }
}
main(){
    FAST;
    ll n;
    cin >> n;
    for(ll i =0;i<n-1;i++){
        ll u, v;
        cin >> u >> v;
        d[u].pb(v);
        d[v].pb(u);
    }
    dfs(1);
    if(ok)cout << "YES";
    else cout << "NO";
}