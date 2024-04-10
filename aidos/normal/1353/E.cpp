#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
const int maxn = (int) 1e6 + 10;
const int mod = (int) 1e9 + 7;
string s;
int n;
int k;
vector<int> g[maxn];
int cnt;
int ans;
void calc(int pos) {
    int x = 0, y = 0, z = 0, last = -2;
    int cur = 0;
    for(int v: g[pos]) {
        int a, b, c;
        a = x + 1;
        b = min(x, y + v - last - 1);
        c = min(b, z + 1);
        x = a;
        y = b;
        z = c;
        last = v;
    }
    ans = min(ans, cnt - int(g[pos].size()) + z);
}
void solve() {
    cin >> n >> k >> s;
    for(int i = 0; i < n; i++) g[i].clear();
    cnt = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
            cnt++;
            g[i % k].emplace_back(i/k);
        }
    }
    ans = cnt;
    for(int i = 0; i < k; i++) calc(i);
    cout << ans << "\n";
}

int main() {
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}