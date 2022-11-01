#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()

void upd(pair<int, int> &a, pair<int, int> b) {
    a = max(a, b);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    int n; cin >> n;
    vector<int> v(n), c(n), l(n), r(n);
    for(int i = 0; i < n; i++) cin >> v[i] >> c[i] >> l[i] >> r[i];
    vector<unordered_map<int, pair<int, int>>> opt(200001);
    vector<int> dp(n, -1), p(n, -1);
    for(int i = 0; i < n; i++) {
        pair<int, int> x = opt[r[i] + c[i]][l[i]];
        if(x.first == 0 && l[i] != 0) continue;
        dp[i] = v[i] + x.first;
        if(x.first != 0) p[i] = x.second;
        upd(opt[r[i]][l[i] + c[i]], {dp[i], i});
    }
    pair<int, int> ans = {0, 0};
    for(int i = 0; i < n; i++) if(r[i] == 0) ans = max(ans, {dp[i], i});
    if(ans.first == 0) return cout << 0, 0;
    vector<int> vec;
    int u = ans.second;
    do {
        vec.push_back(u);
        u = p[u];
    } while(u != -1);
    sort(all(vec));
    cout << sz(vec) << '\n';
    for(int x : vec) cout << x + 1 << ' ';
}