#include <bits/stdc++.h> 

using namespace std;

#define all(x) begin(x), end(x)

#define int int64_t

const int inf = 1e9 + 7;

const int maxn = 1 << 23;
int sm[maxn], smb[maxn];

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    //random_shuffle(a, a + n);
    int SORT[n];
    iota(SORT, SORT + n, 0);
    sort(SORT, SORT + n, [&](int x, int y) {
        return a[x] < a[y];
    });
    // a[SORT[0]] < ... < a[SORT[n - 1]]
    int mask_sz = 1 << n;
    for(int mask = 1; mask < mask_sz - 1; mask++) {
        for(int i = 0; i < n; i++) {
            if((mask >> i) & 1) {
                sm[mask] += a[i];
            }
        }
    }
    
    
    int p[n];
    iota(p, p + n, 0);
    int cnt = 2 * n;
    while(cnt--) {
        if(n > 2) {
            rotate(p, p + 1, p + n - 1);
        }
        int b[n];
        for(int i = 0; i < n; i++) {
            b[SORT[p[i]]] = SORT[p[(i + 1) % n]];
        }
        memset(smb, 0, sizeof(int) * mask_sz);
        for(int mask = 1; mask < mask_sz - 1; mask++) {
            for(int i = 0; i < n; i++) {
                if((mask >> i) & 1) {
                    smb[mask] += a[b[i]];
                }
            }
            if(smb[mask] == sm[mask]) {
                goto rep;
            }
        }
        for(int i = 0; i < n; i++) {
            cout << a[b[i]] << ' ';
        }
        cout << endl;
        return 0;
        rep:;
    }
    cout << -1 << endl;
    return 0;
}