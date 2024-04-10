#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

const int N = 105;

int a[N], n;

struct BIT {
    vector<int> bit;
    int maxn;
    
    BIT(int n) {
        bit.resize(n + 2, 0);
        maxn = n + 1;
    }

    void update(int k, int val) {
        for (int i = k; i < maxn; i += (i & (-i))) {
            bit[i] = max(bit[i], val);
        }
    }

    int get(int k) {
        int res = 0;
        for (int i = k; i > 0; i -= (i & (-i))) {
            res = max(res, bit[i]);
        }
        return res;
    }
};

int solve(int t) {
    vector<int> b;
    for (int i = 0; i < t; i++) {
        for (int j = 1; j <= n; j++) b.pb(a[j]);
    }
    int res = 0;
    BIT bit = BIT(305);
    for (int e : b) {
        int u = bit.get(e) + 1;
        res = max(res, u);
        bit.update(e, u);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int t;
    cin >> n >> t;
    vector<int> cnt(305);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    int mx = 0;
    for (int e : cnt) mx = max(mx, e);
    int tt = min(t, 10000);
    t -= tt;
    int res = solve(tt) + mx * t;
    cout << res;
    return 0;   
}