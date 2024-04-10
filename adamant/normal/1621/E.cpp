#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

const int inf = 1e9;
const int maxn = 1e5 + 42;

void solve() {
    int n, m;
    cin >> n >> m;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n, greater<int>());
    vector<int> gr[m];
    int s[m], k[m];
    for(int i = 0; i < m; i++) {
        cin >> k[i];
        gr[i].resize(k[i]);
        s[i] = 0;
        for(int j = 0; j < k[i]; j++) {
            cin >> gr[i][j];
            s[i] += gr[i][j];
        }
    }
    int p[m];
    iota(p, p + m, 0);
    sort(p, p + m, [&](int a, int b) {
        return s[a] * k[b] > s[b] * k[a];
    });
    int match[m][3], pr[m + 1][3];
    pr[0][0] = pr[1][0] = pr[2][0] = 0;
    memset(match, 0, sizeof match);
    for(int i = 0; i < m; i++) {
        match[i][0] = s[p[i]] <= a[i] * k[p[i]];
        if(i > 0) {
            match[i][1] = s[p[i]] <= a[i - 1] * k[p[i]];
        }
        if(i + 1 < n) {
            match[i][2] = s[p[i]] <= a[i + 1] * k[p[i]];
        }
        for(int z = 0; z < 3; z++) {
            pr[i + 1][z] = pr[i][z] + match[i][z];
        }
    }
    auto matched = [&](int z, int l, int r) {
        if(l >= r) {
            return true;
        } else {
            return r - l == pr[r][z] - pr[l][z];
        }
    };
    string ans[m];
    for(int zi = 0; zi < m; zi++) {
        int i = p[zi];
        for(int j = 0; j < k[i]; j++) {
            int ts = s[i] - gr[i][j];
            int tk = k[i] - 1;
            int l = -1, r = m;
            while(r - l > 1) {
                int M = (l + r) / 2;
                if(s[p[M]] * tk > ts * k[p[M]]) {
                    l = M;
                } else {
                    r = M;
                }
            }
            int new_i = r;
            int cur;
            if(new_i > zi) {
                cur = matched(0, 0, zi) 
                    & matched(1, zi + 1, new_i) 
                    & matched(0, new_i, m)
                    & (a[new_i - 1] * tk >= ts);
            } else {
                cur = matched(0, 0, new_i)
                    & matched(2, new_i, zi)
                    & matched(0, zi + 1, m)
                    & (a[new_i] * tk >= ts);
            }
            ans[i] += '0' + cur;
        }
    }
    for(auto it: ans) {
        cout << it;
    }
    cout << "\n";
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}