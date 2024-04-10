#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long

const int INF = 1e9 + 1;
const long long INFLL = 1e18 + 1;
const int MAXN = 3e5;

bool IS_MULTITEST = 0;

vector<int> f;

void incr(int x) {
    for (; x < (int)f.size(); x = (x | (x + 1))) f[x] += 1;
}

int get(int x) {
    int ans = 0;
    for (; x >= 0; x = (x & (x + 1)) - 1) ans += f[x];
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &c : a) cin >> c;
    set<int> now;
    vector<int> last(n + 1, -1);
    for (int i = 0; i < n; i++) last[a[i]] = i;
    for (int j = n + 1; j <= MAXN; j++) now.insert(j);
    for (int i = 0; i <= n; i++) if (last[i] == -1) now.insert(i);
    f.resize(n + 1);
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[i] = *now.begin();
        now.erase(now.begin());
        if (ans[i] <= n) incr(ans[i]);
        if (get(a[i] - 1) != a[i]) {
            cout << -1;
            return;
        }
        if (last[a[i]] == i) now.insert(a[i]);
    }
    for (auto &c : ans) cout << c << " ";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    if (IS_MULTITEST) cin >> t;
    while (t--) solve();
    return 0;
}