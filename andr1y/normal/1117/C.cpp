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
pll c1, c2;
ll n, ups = 0, rights = 0, lefts = 0, downs = 0;
string s;
ll get_length(ll k){
    ll delta_x = rights-lefts;
    ll delta_y = ups-downs;
    pll res_point(c1.x+delta_x*(k/n), c1.y+delta_y*(k/n));
    for(ll i=0;i<k%n;i++)
        switch(s[i]){
            case 'U': res_point.y++; break;
            case 'D': res_point.y--; break;
            case 'R': res_point.x++; break;
            case 'L': res_point.x--; break;
        }
    return abs(c2.x - res_point.x) + abs(c2.y - res_point.y);
}
main(){
    FAST;
    cin >> c1.x >> c1.y >> c2.x >> c2.y;
    cin >> n;
    for(ll i=0;i<n;i++){
        char c;
        cin >> c;
        s += c;
        if(c == 'U') ups++;
        if(c == 'D') downs++;
        if(c == 'L') lefts++;
        if(c == 'R') rights++;
    }
    ll l = 0, r = 1e18;
    while(r-l>1){
        ll m = (l+r)/2;
        ll v = get_length(m);
        if(v <= m) r = m;
        else l = m;
    }
    //cout << l << " " << r << endl;
    if(get_length(l)<=l) cout << l;
    else if(get_length(r)<=r) cout << r;
    else cout << -1;
    cout << endl;
}