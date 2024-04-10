#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    const int INF = 1e9 + 1;

    int k, n;
    cin >> n >> k;
    vector<int> res(1 << k, INF), mn(1 << k, INF), mx(1 << k, -INF);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mn[x] = mx[x] = x;
    }

    for (int i = 1; i < (1 << k); i <<= 1) {
        for (int j = 0; j < i; j++) {
            for (int x = j; x < (1 << k); x += (i << 1)) {
                res[x] = res[x + i] = min(res[x], res[x + i]);
                res[x] = min(res[x], mn[x + i] - mx[x]);
                res[x + i] = min(res[x + i], i * 2 + mn[x] - mx[x + i]);
                int min_vals[2] = {mn[x], mn[x + i]};
                int max_vals[2] = {mx[x], mx[x + i]};
                mn[x] = min(min_vals[0], min_vals[1]);
                mx[x] = max(max_vals[0], max_vals[1]);
                mn[x + i] = min(min_vals[0] ^ i, min_vals[1] ^ i);
                mx[x + i] = max(max_vals[0] ^ i, max_vals[1] ^ i); 
            }
        }
    }

    for (int i = 0; i < (1 << k); i++) cout << res[i] << ' ';
    cout << '\n';

    return 0;
}