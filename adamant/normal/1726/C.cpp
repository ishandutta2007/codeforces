#include <bits/stdc++.h>

using namespace std;

#define int int64_t
const int mod = 998244353;

const int maxn = 2e5 + 42;
int par[maxn];

int get(int v) {
    return v == par[v] ? v : par[v] = get(par[v]);
}

int uni(int a, int b) {
    a = get(a); b = get(b);
    return a != b;
}

void solve() {
    int n;
    cin >> n;
    for(int i = 0; i < 2 * n; i++) {
        par[i] = i;
    }
    int ans = 2 * n;
    string s;
    vector<int> op;
    cin >> s;
    vector<bool> ok(2 * n);
    for(int i = 0; i < 2 * n; i++) {
        if(s[i] == '(') {
            op.push_back(i);
        } else {
            if(op.size()) {
                ok[i] = true;
                if(op.back() > 0 && ok[op.back() - 1]) {
                    ans -= uni(i, op.back() - 1);
                }
                ans -= uni(i, op.back());
                op.pop_back();
            }
        }
    }
    cout << ans << "\n";
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}