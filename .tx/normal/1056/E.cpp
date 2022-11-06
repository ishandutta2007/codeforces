#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;
auto csz = [](const auto& c) { return int(c.size());};

mt19937 rng((size_t) make_shared<char>().get());

const llong p1 = 31;
const llong p2 = 239;
const llong M1 = int(1e9) + 7;
const llong M2 = int(1e9) + 31;

llong h1[1111111];
llong h2[1111111];
llong ps1[1111111];
llong ps2[1111111];

llong get1(int l, int r) {
    return (h1[r] - h1[l] * ps1[r - l] + M1 * M1) % M1;
}

llong get2(int l, int r) {
    return (h2[r] - h2[l] * ps2[r - l] + M2 * M2) % M2;
}

pair<llong, llong> get(int l, int r) {
    return pair(get1(l, r), get2(l, r));
}


int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
    rng.seed(0);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string s, t;
    cin >> s >> t;

    int n = csz(s);
    int m = csz(t);

    int c0 = 0, c1 = 0;
    for (char c : s) {
        if (c == '0') {
            c0++;
        } else {
            c1++;
        }
    }

    if (c0 < c1) {
        swap(c0, c1);
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                s[i] = '1';
            } else {
                s[i] = '0';
            }
        }
    }

    ps1[0] = ps2[0] = 1;
    for (int i = 0; i < m; i++) {
        ps1[i + 1] = ps1[i] * p1 % M1;
        ps2[i + 1] = ps2[i] * p2 % M2;

        h1[i + 1] = (h1[i] * p1 + t[i] - 'a' + 1) % M1;
        h2[i + 1] = (h2[i] * p2 + t[i] - 'a' + 1) % M2;
    }

    llong ans = 0;

    for (int l0 = 1; l0 <= m; l0++) {
        if (1LL * l0 * c0 > m) {
            break;
        }
        int l1 = c1 == 0 ? 0 : ((m - l0 * c0) / c1);
        if (l0 * c0 + l1 * c1 != m || l0 == 0 || l1 == 0) {
            continue;
        }

        int s0 = -1, s1 = -1;
        int cp = 0;
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                if (s0 == -1) {
                    s0 = cp;
                } else {
                    if (get(s0, s0 + l0) != get(cp, cp + l0)) {
                        ok = false;
                        break;
                    }
                }
                cp += l0;
            } else {
                if (s1 == -1) {
                    s1 = cp;
                } else {
                    if (get(s1, s1 + l1) != get(cp, cp + l1)) {
                        ok = false;
                        break;
                    }
                }
                cp += l1;
            }
        }
        const pair<llong, llong> &g1 = get(s0, s0 + l0);
        const pair<llong, llong> &g2 = get(s1, s1 + l1);
        if (g1 == g2) {
            ok = false;
        }

        if (ok) {
            ans++;
        }
    }

    cout << ans;

    return 0;
}//txkpod