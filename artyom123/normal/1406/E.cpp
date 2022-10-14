#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double

const int INF = 2e9 + 1;
const ll INFLL = 1e18 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> e(n + 1, INF), pr;
    for (int i = 2; i <= n; i++) {
        if (e[i] != INF) continue;
        e[i] = i;
        pr.pb(i);
        if (n / i >= i) {
            for (int j = i * i; j <= n; j += i) {
                e[j] = min(e[j], i);
            }
        }
    }
    vector<vector<int>> div(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j * j <= i; j++) {
            if (i % j != 0) continue;
            if (e[j] == j) div[j].pb(i);
            if (i / j != j && e[i / j] == i / j) div[i / j].pb(i);
        }
    }
    int m = pr.size();
    int block = 97;
    int exp_total = n;
    vector<int> fact;
    vector<int> usd(n + 1);
    int mn = -1;
    for (int i = 0; i < m; i += block) {
        for (int j = i; j < m && j < i + block; j++) {
            int p = pr[j];
            cout << 'B' << " " << p << endl;
            int ans;
            cin >> ans;
            int exp = 0;
            for (auto &c : div[p]) {
                if (usd[c] == 0) exp++;
            }
            if (ans != exp) {
                fact.pb(p);
            }
            for (auto &c : div[p]) {
                if (usd[c] == 0) {
                    usd[c] = 1;
                    exp_total--;
                }
            }
        }
        if (mn != -1) continue;
        cout << 'A' << " " << 1 << endl;
        int ans;
        cin >> ans;
        if (ans != exp_total) mn = i;
    }
    if (mn == -1) {
        cout << 'C' << " " << 1 << endl;
        return 0;
    }
    int ans = 1;
    for (int j = mn; ; j++) {
        cout << 'A' << " " << pr[j] << endl;
        int res; cin >> res;
        if (res) {
            fact.pb(pr[j]);
            break;
        }
    }
    for (auto &p : fact) {
        ans *= p;
        int now = p;
        while (now <= n / p) {
            now *= p;
            cout << 'A' << " " << now << endl;
            int res; cin >> res;
            if (res == 0) break;
            ans *= p;
        }
    }
    cout << 'C' << " " << ans << endl;
    return 0;
}