#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

const int maxn = 2e5 + 42;
const int logn = 31;
const int maxs = 2 * logn * maxn;

int to[maxs][2], cnt[maxs], mx[maxs];
int sz = 1;

void add(int x) {
    int v = 0;
    for(int i = logn - 1; i >= 0; i--) {
        int c = (x >> i) & 1;
        if(!to[v][c]) {
            to[v][c] = sz++;
        }
        v = to[v][c];
        cnt[v]++;
    }
}

int get(int v = 0) {
    bool sep = cnt[to[v][0]] && cnt[to[v][1]]; 
    int ans = sep;
    if(to[v][0]) ans = max(ans, get(to[v][0]) + sep);
    if(to[v][1]) ans = max(ans, get(to[v][1]) + sep);
    return ans;
}

void solve() {
    int n;
    cin >> n;
    int b[n];
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        add(b[i]);
    }
    cout << n - 1 - get() << "\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t = 1;//cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}