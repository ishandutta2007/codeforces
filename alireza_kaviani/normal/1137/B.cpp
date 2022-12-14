/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author alireza_kaviani
 */

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define Mp                          make_pair
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << " = " << x << endl
#define SZ(x)                       ll(x.size())
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define set_random                  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

set_random;

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll Mod[4] = {998244353 , ll(1e9 + 7) , ll(1e9 + 9) , ll(1e9 + 21)} , Base[4];
vector<ll> primes;

struct Hash {
    ll n , mod;
    vector<ll> pw , invs , hs;

    Hash(string s, ll base, ll mod) {
        n = s.size() + 10;
        pw.resize(n);
        invs.resize(n);
        hs.resize(n);

        ll inv = poww(base, mod - 2, mod);
        pw[0] = 1;
        invs[0] = 1;

        for (ll i = 1; i < n; i++) {
            pw[i] = pw[i - 1] * base % mod;
            invs[i] = invs[i - 1] * inv % mod;
        }

        for (ll i = 0; i < s.size(); i++) {
            hs[i + 1] = hs[i] + (s[i] - 47) * pw[i] % mod;
        }

        this->mod = mod;
    }

    ll get(ll l, ll r) {
        r++;
        return (hs[r] - hs[l] + mod) % mod * invs[l] % mod;
    }
};

struct Hashes {
    vector<Hash> vec;

    Hashes(){
        return;
    }

    Hashes(string s) {
        for (ll i = 0; i < 4; i++) {
            vec.push_back(Hash(s, Base[i], Mod[i]));
        }
    }

    vector<ll> get(ll l, ll r) {
        vector<ll> ans;
        for (ll i = 0; i < vec.size(); i++) {
            ans.push_back(vec[i].get(l, r));
        }
        return ans;
    }
};

ll n , m , l , cnt[2] , cnt2[2];
string s , t , ans;
Hashes hs;

ll Prime(ll x){
    for(ll i = 2 ; i * i <= x ; i++){
        if(x % i == 0)  return 0;
    }
    return 1;
}

int main() {
    fast_io;

    for(ll i = 30 ; i <= 1e4 ; i++){
        if(Prime(i))    primes.push_back(i);
    }
    for(ll i = 0 ; i < 4 ; i++){
        Base[i] = primes[rng() % SZ(primes)];
    }

    cin >> s >> t;
    n = s.size();
    m = t.size();
    hs = Hashes(t);

    for(ll i = 1 ; i < m ; i++){
        if(hs.get(i , m - 1) == hs.get(0 , m - i - 1)){
            l = max(l , m - i);
        }
    }
    for(ll i = 0 ; i < n ; i++){
        cnt[s[i] - 48]++;
    }

    ans = t;
    t = t.substr(l , m);
    while(ans.size() <= n)  ans += t;

    ans.resize(n);
    for(ll i = 0 ; i < n ; i++){
        if(cnt2[ans[i] - 48] == cnt[ans[i] - 48]){
            ans[i] = (ans[i] == '1' ? '0' : '1');
        }
        cnt2[ans[i] - 48]++;
    }
    cout << ans << endl;


    return 0;
}
/*

*/