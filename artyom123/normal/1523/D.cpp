 #include <bits/stdc++.h>

using namespace std;

#define pb emplace_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pii pair<int, int>
#define puu pair<unsigned, unsigned>
#define ll long long 
#define mp make_pair

const long long INFLL = 1e18;
const int INF = 1e9 + 1;
mt19937 gen(time(0));

int main() {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    int n, m, p;
    cin >> n >> m >> p;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        ll x = 0;
        for (auto &c : s) {
            x *= 2;
            if (c == '1') x++;
        }
        a[i] = x;
    }
    ll ans = 0;
    for (int it = 0; it < 20; it++) {
        if (clock() * 1.0 / CLOCKS_PER_SEC > 2.5) break;
        int i = gen() % n;
        unordered_map<ll, int> cnt;
        for (int j = 0; j < n; j++) cnt[a[i] & a[j]]++;
        unordered_map<ll, int> cnt1;
        for (auto &c : cnt) {
            for (ll x = c.fi; x > 0; x = ((x - 1) & c.fi)) cnt1[x] += c.se;
        }
        for (auto &c : cnt1) {
            if (__builtin_popcountll(ans) < __builtin_popcountll(c.fi)) {
                if (c.se >= (n + 1) / 2) ans = c.fi;
            }
        }
    }
    vector<int> pe;
    while (ans) {
        pe.pb(ans % 2);
        ans /= 2;
    }
    while ((int)pe.size() < m) pe.pb(0);
    reverse(all(pe));
    for (auto &c : pe) cout << c;
    return 0;
}