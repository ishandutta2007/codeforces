// #pragma GCC optimize("O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()

using ll = long long;

template <typename T, typename S = istream>
void read(vector<T>& vec, S& in = cin) {
    for (auto& elem : vec) {
        in >> elem;
    }
}

template <typename T, typename S = ostream>
void write(const vector<T>& vec, char delim = ' ', char last = '\n', S& out = cout) {
    bool first = true;
    for (auto& elem : vec) {
        if (!first) {
            out << delim;
        }
        out << elem;
        first = false;
    }
    out << last;
}

const int MOD = 1e9 + 7;
const int NUMB = 998'244'853;
const int DUMB = 998'244'353;

ll binpow(ll a, ll p, ll mod = MOD) {
    ll res = 1;
    while (p) {
        if (p & 1) {
            res = res * a % mod;
        }
        p >>= 1;
        a = a * a % mod;
    }
    return res;
}

const int N = 2e5 + 5;

int ver[N * 2];
int pos[N * 2];

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> counter(101);
    for (int i = 0; i <= 100; i++) {
        counter[i].second = i;
    }
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        counter[a[i]].first++;
    }
    sort(counter.rbegin(), counter.rend());
    if (counter[0].first == counter[1].first) {
        cout << n << endl;
        return;
    }
    int freq = counter[0].second;
    int ans = 0;
    for (int x = 1; x <= 100; x++) {
        if (x == freq) continue;
        pos[N] = -1;
        ver[N] = x;
        int sum = N;
        for (int i = 0; i < n; i++) {
            if (a[i] == x) sum++;
            if (a[i] == freq) sum--;
            if (ver[sum] < x) {
                pos[sum] = i;
                ver[sum] = x;
            }
            ans = max(ans, i - pos[sum]);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
    return 0;
}