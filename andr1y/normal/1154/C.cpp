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
#define N 200000
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
ll count(ll a, ll b, ll c, ll day){
    ll xx = min(a/3, min(b/2, c/2));
    a-=3*xx, b-=2*xx, c-=2*xx;
    ll dn = 0;
    ll dy = day;
    while(a >= 0 && b>=0 && c>=0){
        dn++;
        if(dy == 0 || dy == 3 || dy == 6) a--;
        if(dy == 1 || dy == 5) b--;
        if(dy == 2 || dy == 4) c--;
        dy++;
        dy%=7;
    }
    return 7*xx + dn - 1;
}
main(){
    FAST;
    ll a, b, c;
    cin >> a >> b >> c;
    ll maxr = 0;
    for(ll i = 0;i<7;i++){
        maxr = max(maxr, count(a, b, c, i));
    }
    cout << maxr;
}