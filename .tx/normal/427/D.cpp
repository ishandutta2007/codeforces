#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;
auto isz = [](const auto& c) { return int(c.size());};

mt19937 rng((size_t) make_shared<char>().get());

vector<int> cz(const string& s) {
    int n = isz(s);
    int l = 0, r = 0;
    vector<int> z(n);
    for (int i = 1; i < n; i++) {
        if (i < r) {
            z[i] = min(z[i - l], r - i);
        }
        while (i + z[i] < n && s[i + z[i]] == s[z[i]]) {
            z[i]++;
        }
        if (i + z[i] > r) {
            r = i + z[i];
            l = i;
        }
    }
    return z;
}

pair<int, int> f(const string& s, const string& t) {
    vector<int> z = cz(s + "#" + t);
    int n = isz(z);
    vector<int> cnt(n);
    for (int i : z) {
        cnt[i]++;
    }
    int lst = 0;
    int cur = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < cnt[i]; j++) {
            lst = cur;
            cur = i;
        }
    }
    return {lst, cur};
}

int main(int argc, char** argv) {
#ifdef VSE
    if (argc > 1) freopen(argv[1], "r", stdin);
    rng.seed(0);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string s, t;
    cin >> s >> t;
    int ans = 1e9;
    for (int i = 0; i < isz(s); i++) {
        auto x = f(s.substr(i, isz(s) - i), s);
        auto y = f(s.substr(i, isz(s) - i), t);
        if (x.first == x.second || y.first == y.second) {
            continue;
        }
//        cout << "(" << x.first << ", " << x.second << ") (" << y.first << ", " << y.second << ")\n";
        int d = min(x.second, y.second) - max(x.first, y.first);
        if (d > 0) {
            ans = min(ans, max(x.first, y.first) + 1);
        }
    }

    if (ans == 1e9) {
        ans = -1;
    }
    cout << ans << "\n";

    return 0;
}