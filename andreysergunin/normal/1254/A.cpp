#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = double;
using pii = pair<int, int>;
using uint = unsigned int;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;

char get(int k) {
    if (k < 10) {
        return char(k + '0');
    }
    k -= 10;
    if (k < 26) {
        return char(k + 'a');
    }
    k -= 26;
    return char(k + 'A');
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> s(n);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        for (int j = 0; j < m; ++j) {
            cnt += s[i][j] == 'R';
        }
    }

    int cur = 0;
    int x = 0;

    vector<int> order(m);
    iota(all(order), 0);
    vector<string> res(n, string(m, '.'));
    for (int i = 0; i < n; ++i) {
        reverse(all(order));
        for (int j : order) {
            if (s[i][j] == 'R') {
                ++cur;
            }
            s[i][j] = get(x);
            if (x < (cnt % k)) {
                if (cur == cnt / k + 1) {
                    ++x;
                    cur = 0;
                }
            } else {
                if (cur == cnt / k) {
                    ++x;
                    cur = 0;
                }
            }

            if (x == k) {
                --x;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << s[i] << "\n";
    }
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(12) << fixed;
    cerr << setprecision(12) << fixed;  

    int tests;
    cin >> tests;
    while (tests--) {
        solve();
    }

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}