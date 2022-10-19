#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int l[N], r[N];
int n;
int bit[2 * N];

struct BIT {
    int bit[2 * N];
    int maxn;
    
    BIT() {
        memset(bit, 0, sizeof bit);
        maxn = 2 * N;
    }

    void update(int k, int val) {
        for (int i = k; i < maxn; i += (i & (-i))) {
            bit[i] += val;
        }
    }

    int get(int k) {
        int res = 0;
        for (int i = k; i > 0; i -= (i & (-i))) {
            res += bit[i];
        }
        return res;
    }
} bit0, bit1;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> l[i] >> r[i];
    set<int> toComp;
    map<int, int> comp;
    for (int i = 1; i <= n; i++) toComp.insert(l[i]), toComp.insert(r[i]);
    int counter = 0;
    for (int e : toComp) comp[e] = ++counter;
    for (int i = 1; i <= n; i++) l[i] = comp[l[i]], r[i] = comp[r[i]];
       
    for (int i = 1; i <= n; i++) bit0.update(l[i], 1), bit1.update(r[i], 1);

    int res = 1e9;
    for (int i = 1; i <= n; i++) {
        res = min(res, bit1.get(l[i] - 1) + bit0.get(2 * n) - bit0.get(r[i]));
    }

    for (int i = 1; i <= n; i++) bit0.update(l[i], -1), bit1.update(r[i], -1);

    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cout.tie(0);

    int ntest;
    cin >> ntest;

    while (ntest--) solve();

    return 0;
}