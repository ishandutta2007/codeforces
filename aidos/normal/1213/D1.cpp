#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int) 1e6 + 10;
const int mod = (int) 1e9 + 7;
const int inf = (1 << 30) - 1;
const double pi = acos(-1);
const double eps = 1e-15;
int n, k;
vector<int> g[maxn];

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int cnt = 0;
        while (x >= 1) {
            g[x].emplace_back(cnt);
            cnt++;
            x /= 2;
        }
    }
    int ans = inf;
    for(int i = 1; i < maxn; i++) {
        if(g[i].size() < k) continue;
        sort(g[i].begin(), g[i].end());
        int cur = 0;
        for(int j = 0; j < k; j++) {
            cur += g[i][j];
        }
        ans = min(ans, cur);
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}