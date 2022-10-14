#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long

const int INF = 1e9 + 1;
const long long INFLL = 1e18 + 1;

bool IS_MULTITEST = 1;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (auto &c : p) cin >> c;
    vector<int> ans;
    ans.pb(p[0]);
    ans.pb(p[1]);
    for (int i = 2; i < n; i++) {
        if (p[i] > ans.back() && ans.back() > ans[ans.size() - 2]) ans.pop_back();
        else if (p[i] < ans.back() && ans.back() < ans[ans.size() - 2]) ans.pop_back();
        ans.pb(p[i]);
    }
    cout << ans.size() << "\n";
    for (auto &c : ans) cout << c << " ";
    cout << "\n";
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