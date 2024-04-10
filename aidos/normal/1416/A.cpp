#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n;
vector<int> g[maxn];
int a[maxn];
void solve() {
    cin >> n;
    for(int i = 0; i <= n; i++) {
        g[i].clear();
        a[i] = inf;
    }

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        g[x].emplace_back(i);
    }
    for(int i = 1; i <= n; i++) {
        if(g[i].size() == 0) continue;
        int cur = max(g[i][0], n - g[i].back() - 1);
        for(int j=1; j < g[i].size(); j++) {
            cur = max(g[i][j] - g[i][j-1] - 1, cur);
        }
        a[cur + 1] = min(a[cur + 1], i);
    }
    for(int i = 2; i <= n; i++) a[i] = min(a[i], a[i-1]);
    for(int i = 1; i <= n; i++) {
        if(a[i] == inf) a[i] = -1;
        cout << a[i] << " ";
    }
    cout << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int t = 1;
    //scanf("%d", &t);
    cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}