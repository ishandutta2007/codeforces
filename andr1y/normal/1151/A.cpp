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
#define N 1000000
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
#define stopit cout << "NO"; exit(0);
main(){
    FAST;
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll minc = INF;
    for(ll i =0;i<n-3;i++){
        ll sum_c = 0;
        sum_c += min('Z'-s[i] + 1, s[i]-'A');
        if(s[i+1]>'C') sum_c += min('Z'-s[i+1] + 3, s[i+1]-'C');
        else sum_c += 'C' - s[i+1];
        if(s[i+2]>'T') sum_c += min('Z'-s[i+2] + ('T'-'A' + 1), abs(s[i+2]-'T'));
        else sum_c += min('T'-s[i+2], s[i+2]-'A'+'Z'-'T'+1);
        if(s[i+3]>'G') sum_c += min('Z'-s[i+3] + ('G'-'A' + 1), abs(s[i+3]-'G'));
        else sum_c += 'G' - s[i+3];
        minc = min(minc, sum_c);
    }
    cout << minc;
}