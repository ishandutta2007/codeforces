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
int a, b;
int ans[55][55];
pii x[55];
int cnta[55];
void solve() {
    cin >> n >> m >> a >> b;
    for(int i = 0; i < m; i++) {
        cnta[i] = 0;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            x[j] = make_pair(cnta[j], j);
            ans[i][j] = 0;
        }
        sort(x, x + m);
        for(int j = 0; j < a; j++) {
            cnta[x[j].second]++;
            ans[i][x[j].second] = 1;
        }
    }
    for(int i = 0; i < m; i++) {
        if(cnta[i] != b) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) cout << ans[i][j];
        cout << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}