#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
const int maxn = (int) 2e5 + 10;
const int mod = (int) 1e9 + 7;
int n, m;
ll a[maxn];
int g[500][500];
int d[555];
int get(int s, int t) {
    for(int i = 0; i < m; i++) d[i] = -1;
    d[s] = 0;
    queue<int> q;
    q.push(s);
    while(q.size() > 0) {
        int v = q.front();
        q.pop();
        for(int i = 0; i < m; i++) {
            if(g[v][i] == 1 && d[i] == -1) {
                d[i] = d[v] + 1;
                q.push(i);
            }
        }
    }
    return d[t];
}
void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        if(x > 0) a[m++] = x;
    }
    if(m > 60 * 2) {
        cout << 3 << "\n";
        return;
    }
    for(int i = 0; i < m; i++)  {
        for(int j = 0; j < m; j++) {
            if(i == j) continue;
            if(a[i] & a[j]) {
                g[i][j] = 1;
            }
        }
    }
    int ans = -1;
    for(int i = 0; i < m; i++) {
        for(int j = i + 1; j < m; j++) {
            if(g[i][j] == 1) {
                g[i][j] = 0;
                g[j][i] = 0;
                int cur = get(i, j);
                if(cur != -1) {
                    if(ans == -1) ans = cur + 1;
                    else ans = min(ans, cur + 1);
                }
                g[i][j] = g[j][i] = 1;
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}