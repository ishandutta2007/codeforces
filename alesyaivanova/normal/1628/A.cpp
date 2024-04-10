#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

const int maxn = 2e5 + 9;
int a[maxn];
vector<int> pos[maxn];
int n;

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pos[a[i]].pb(i);
    }
    for (int i = 0; i <= n; i++) {
        reverse(all(pos[i]));
    }
    int st = -1;
    vector<int> ans;
    while (st < n - 1) {
        int ma = st;
        int cur = n + 1;
        for (int i = 0; i <= n; i++) {
            while (!pos[i].empty() && pos[i].back() <= st) {
                pos[i].pop_back();
            }
            if (!pos[i].empty()) {
                ma = max(ma, pos[i].back());
            } else {
                cur = i;
                break;
            }
        }
        ans.push_back(cur);
        if (st == ma) {
            ma++;
        }
        st = ma;
    }
    cout << ans.size() << "\n";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << "\n";
    for (int i = 0; i <= n; i++) {
        pos[i] = {};
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}