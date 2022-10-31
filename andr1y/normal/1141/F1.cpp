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
#define N 50
#define INF 100000
#define NINF -INF
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
ll a[N], pref[N];
main(){
    FAST;
    ll n;
    cin >> n;
    map<ll, vector<pll> > cnt;
    ll maxsum = NINF, minsum = INF;
    for(ll i=0;i<n;i++){
        cin >> a[i];
        pref[i] = pref[i-1]+a[i];
        for(ll j =0;j<=i;j++){
            ll ts = pref[i]-pref[j-1];
            maxsum = max(maxsum, ts);
            minsum = min(minsum, ts);
            cnt[ts].pp(j, i);
        }
    }
    ll maxc = 0;
    vector<pll> res;
    for(auto i : cnt){
        ll cur = 0;
        ll r = -1;
        vector<pll> now;
        for (auto seg: i.y)
            if (seg.x > r) {
                cur++;
                now.pb(seg);
                r = seg.y;
            }
        if(cur > maxc){
            maxc = cur;
            res = now;
        }
    }
    cout << res.size() << endl;
    for(auto i : res) cout << i.x+1 << " " << i.y+1 << endl;
}