#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)5e5 + 10;
const int mod = (int) 1e9 + 7;
const int inf = (1<<30) - 1;
int n, m;
vector<int> a;
vector<int> g[maxn];
int u[maxn];
int dfs(int v) {
    int res = v;
    u[v] = 1;
    for(int &to: g[v]) {
        if(u[to] == 0) {
            res = min(res, dfs(to));
        }
    }
    return res;
}
void solve() {
    cin >> n;
    int cnt = 0;

    int sum = 0;
    for(int i = 0; i < 2 * n - 1; i++) {
        int x;
        cin >> x;
        if(x < 0) cnt++;
        a.emplace_back(abs(x));
        sum += abs(x);
    }
    sort(a.begin(), a.end());
    for(int i = 0; i <= 2 * n - 1; i++) {
        for(int j = 0; j <= min(i, n); j++) {
            int x = i - j + (n - j);
            if(x >= 0 && x <= 2 * n - 1) {
                g[i].emplace_back(x);
            }
        }
    }
    cnt = dfs(cnt);
    for(int i = 0; i < cnt; i++) {
        sum -= 2 * a[i];
    }
    cout << sum << "\n";
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
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