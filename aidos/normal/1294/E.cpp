#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld ;
using namespace std;
const int maxn = (int)5e5 + 10;
const int mod = (int) 1e9 + 7;
int n;
int m;
int cnt[maxn];
vector<int> g[maxn];
int calc(vector<int> d, int rem) {
    for(int i = 0; i < n; i++) {
        cnt[i] = 0;
        g[i * m + rem].clear();
    }
    for(int i = 0; i < d.size(); i++) {
        g[d[i]].emplace_back(i);
    }
    for(int i = 0; i < n; i++) {
        int x = i * m + rem;
        for(const int &pos: g[x]) {
            if(pos < i) cnt[n + (pos - i)]++;
            else cnt[pos - i]++;
        }
    }
    int ans = n;
    for(int i = 0; i < n; i++) {
        ans = min(ans, n - cnt[i] + i);
    }
    return ans;
}
void solve() {
    cin >> n >> m;
    vector < vector<int> > a(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            a[i][j]--;
        }
    }
    int ans = 0;
    for(int i = 0; i < m; i++) {
        vector<int> cur;
        for(int j = 0; j < n; j++) {
            cur.emplace_back(a[j][i]);
        }
        ans += calc(cur, i);
    }
    cout << ans << "\n";
}
int main() {
    int t=1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}