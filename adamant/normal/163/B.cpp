#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
#define int int64_t
#define double long double

const int mod = 1e9 + 7;
const double eps = 1e-18;

const int maxn = 1e5 + 42;
int n, k, h;
int m[maxn], v[maxn], p[maxn];
vector<int> ans;

bool solve(double t) {
    ans.clear();
    for(int i = 0; i < n && ans.size() < k; i++) {
        if(t * v[p[i]] >= (ans.size() + 1) - eps) {
            ans.push_back(p[i]);
        }
    }
    //reverse(all(ans));
    return ans.size() >= k;
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> h;
    for(int i = 0; i < n; i++) {
        cin >> m[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    iota(p, p + n, 0);
    sort(p, p + n, [&](int x, int y) {
       return make_pair(m[x], v[x]) < make_pair(m[y], v[y]); 
    });
    double l = 0, r = k + 1;
    for(int i = 0; i < 600; i++) {
        double m = (l + r) / 2;
        if(solve(m)) {
            r = m;
        } else {
            l = m;
        }
    }
    solve(r + eps);
    assert(ans.size() == k);
    for(int i = 0; i < k; i++) {
        cout << ans[i] + 1 << ' ';
    }
}