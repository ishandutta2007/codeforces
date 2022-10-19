#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef pair<ld, ld> pld;
typedef pair<string, string> pss;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define Mp                          make_pair
#define tab                         '\t'
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << " = " << x << endl
#define SZ(x)                       ll(x.size())
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io                     freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
#define set_random                  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

inline ll input() {
    ll n;
    cin >> n;
    return n;
}

ll pw(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % md, b / 2, md) % md : pw(a * a % md, b / 2, md) % md));
}

const ll MAXN = 2e5 + 10;
const ll INF = 2e9;
const ll MOD = 1e9 + 7; // 998244353;

ll n , x , y , cnt , ans , last[MAXN] , l[MAXN] , r[MAXN];
map<ll , vector<ll>> L , R;
set<ll> st;

int main() {
    fast_io;
    set_random;
    fill(last , last + MAXN , -INF);

    cin >> n >> x >> y;
    for(ll i = 0 ; i < n ; i++)
    {
        cin >> l[i] >> r[i];
        L[l[i]].push_back(i);
        R[r[i]].push_back(i);
        st.insert(l[i]);
        st.insert(r[i]);
    }

    for(auto &i : st)
    {
        for(ll j : L[i])
        {
            cnt++;
            ans += min(x , y * (i - last[cnt]));
            ans %= MOD;
        }

        for(ll j : R[i])
        {
            last[cnt--] = i;
            ans += (r[j] - l[j]) * y;
            ans %= MOD;
        }
    }
    cout << ans << endl;

    return 0;
}
/*
todo :
    1- set constants
    2- check TimeLimit and MemoryLimit
    3- check special test cases
    4- don't forget BS can help you that is good idea(use for loop for floats)
    5- don't forget printf and scanf can help you in your code speed
*/