#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define pp(a, b) pb(mp(a, b))
#define get_bit(n, k) n&(1<<k)
#define endl '\n'
#define vl vector<ll>
#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout);
#define M 1000000007
#define N 200000
#define INF LLONG_MAX
#define NINF -INF-1
#define PAIR_OUT_PRE "("
#define PAIR_OUT_BTW ";"
#define PAIR_OUT_PST "), "
#define VECTOR_OUT_PRE "data: "
#define VECTOR_OUT_BTW ", "
#define VECTOR_OUT_PST endl
using namespace std;
template<typename T, typename D> ostream& operator<<(ostream& os, const pair<T, D> V){return os << PAIR_OUT_PRE << V.x << PAIR_OUT_BTW << V.y << PAIR_OUT_PST;}
template<typename T> ostream& operator<<(ostream& os, const vector<T> V){os << VECTOR_OUT_PRE; for(auto i:V)os << i << VECTOR_OUT_BTW; return os << VECTOR_OUT_PST;}
main(){
    FAST;
    ll n;
    cin >> n;
    cout << (n*(n+1)/2)%2 << endl;
}