#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <chrono>
#include <random>

using namespace std;
#define int long long
vector <int> h, p;
int mod = 1e9 + 7;
const int q = 57;

inline void build_hash(int n, const string& s) {
    h.assign(n + 1, 0);
    p.assign(n + 1, 1);
    for (int i = 1; i <= n; ++i) p[i] = p[i - 1] * q % mod;
    for (int i = 0; i < n; ++i) h[i + 1] = (h[i] * q + s[i] - '0') % mod;
}

inline int get_hash(int l, int r) {
    return ((h[r + 1] - h[l] * p[r - l + 1]) % mod + mod) % mod;
}

int k;

bool gen(string& now, int hash, const map <int, int>& d) {
    if ((int)now.size() == k) {
        return !d.count(hash);
    }
    for (int i = 0; i < 2; ++i) {
        now.push_back('0' + i);
        if (gen(now, (hash * q + i) % mod, d)) return true;
        now.pop_back();
    }
    return false;
}

inline void solve() {
    int n;
    cin >> n >> k;
    string s;
    cin >> s;
    build_hash(n, s);
    map <int, int> d;
    int sum = 0;
    for (int i = 0; i < k; ++i) sum = (sum + p[i]) % mod;
    for (int i = 0; i + k - 1 < n; ++i) {
        int r = i + k - 1;
        d[(sum - get_hash(i, r) + mod) % mod] = 1;
    }
    string now;
    if (gen(now, 0, d)) cout << "YES\n" << now << "\n";
    else cout << "NO\n";
}

const int INF = 1e9;

inline bool check(int a) {
    for (int i = 2; i * i <= a; ++i) {
        if (a % i == 0) return false;
    }
    return true;
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    if (1) {
        mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
        mod = INF + rnd() % INF;
        while (!check(mod)) mod++;
        int t = 1;
        cin >> t;
        while (t--) {
            solve();
        }
    }
}

/*

 */