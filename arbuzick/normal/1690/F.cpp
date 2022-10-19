#include <bits/stdc++.h>

using namespace std;

unsigned long long find_gcd(unsigned long long a, unsigned long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        p[i]--;
    }
    unsigned long long ans = 1;
    vector<int> used(n);
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            string nw = "";
            int v = i;
            while (!used[v]) {
                used[v] = true;
                nw += s[v];
                v = p[v];
            }
            int l = -1, r = -1;
            nw += nw;
            vector<int> z(nw.size() * 2);
            for (int i = 1; i < (int) nw.size(); ++i) {
                if (r > i) {
                    z[i] = min(r - i, z[i - l]);
                }
                while (i + z[i] < (int) nw.size() && nw[z[i]] == nw[i + z[i]]) {
                    z[i]++;
                }
                if (i + z[i] > r) {
                    l = i, r = i + z[i];
                }
            }
            for (int i = 1; i <= (int) nw.size(); ++i) {
                if (z[i] >= (int) nw.size() / 2) {
                    __int128_t nw_ans = ans;
                    nw_ans *= i;
                    ans = nw_ans / find_gcd(ans, i);
                    break;
                }
            }
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}