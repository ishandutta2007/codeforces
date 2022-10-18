#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int const maxn = 2e5 + 5, k = 440;
int link[maxn][26];
int link_rev[maxn][26];
int sum[maxn];
int sum_rev[maxn];
int start[maxn];
int stop[2 * maxn];
int cur = 1, cur_rev = 1;
int z[2 * maxn];

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string t, s, f, rev_t;
    cin >> t;
    for (int i = (int)t.size() - 1; i >= 0; --i) rev_t += t[i];
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> s;
        int p = (int)s.size();
        if (p <= k) {
            int node = 0;
            for (int j = 0; j < p; ++j) {
                if (link[node][s[j] - 'a'] == 0) link[node][s[j] - 'a'] = cur++;
                node = link[node][s[j] - 'a'];
            }
            sum[node]++;
            node = 0;
            for (int j = p - 1; j >= 0; --j) {
                if (link_rev[node][s[j] - 'a'] == 0) link_rev[node][s[j] - 'a'] = cur_rev++;
                node = link_rev[node][s[j] - 'a'];
            }
            sum_rev[node]++;
        }
        else {
            f = s + '!' + t;
            int L = 0, R = 0;
            for (int j = 1; j < (int)f.size(); ++j) {
                if (j <= R) z[j] = min(R - j + 1, z[j - L]);
                else z[j] = 0;
                while (j + z[j] < (int)f.size() && f[j + z[j]] == f[z[j]]) z[j]++;
                if (j + z[j] - 1 > R) {
                    R = j + z[j] - 1, L = j;
                }
            }
            for (int j = (int)s.size() + 1; j < (int)f.size(); ++j) {
                if (z[j] == (int)s.size()) {
                    start[j - (int)s.size()]++;
                    stop[j - 1]++;
                }
            }
        }
    }
    /*for (int i = 1; i <= (int)t.size(); ++i) cout << start[i] << " ";
    cout << '\n';
    for (int i = 1; i <= (int)t.size(); ++i) cout << stop[i] << " ";
    cout << '\n';*/
    ll ans = 0;
    for (int i = 1; i < (int)t.size(); ++i) {
        int lef = stop[i], righ = start[i + 1];
        int node = 0;
        for (int j = i + 1; j <= min((int)t.size(), i + k); ++j) {
            if (link[node][t[j - 1] - 'a'] == 0) break;
            node = link[node][t[j - 1] - 'a'];
            righ += sum[node];
        }
        node = 0;
        for (int j = i; j >= max(1, i - k); --j) {
            if (link_rev[node][t[j - 1] - 'a'] == 0) break;
            node = link_rev[node][t[j - 1] - 'a'];
            lef += sum_rev[node];
        }
        ans = ans + (ll)lef * (ll)righ;
    }
    cout << ans << '\n';
    return 0;
}