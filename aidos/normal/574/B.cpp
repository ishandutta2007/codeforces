#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
int n, m;
int a[4040][4040];
pii x[4040];
int cnt[4040];
void solve() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> x[i].first >> x[i].second;
        a[x[i].first][x[i].second] = 1;
        a[x[i].second][x[i].first] = 1;
        cnt[x[i].first]++;
        cnt[x[i].second]++;
    }
    int ans = -1;
    for(int v = 1; v <= n; v++) {
        for(int i = 0; i < m; i++) {
            if(x[i].first == v || x[i].second == v) continue;
            if(!a[v][x[i].first]) continue;
            if(!a[v][x[i].second]) continue;
            int cur = cnt[v] + cnt[x[i].first] + cnt[x[i].second]-6;
            if(ans == -1 || ans > cur) ans = cur;
        }
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
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}