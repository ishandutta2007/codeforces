#include <bits/stdc++.h>

using namespace std;
#define link alflak
#define fpos ladla

#define int int64_t
#define all(x) begin(x), end(x)
#define rall(x) x.rbegin(), x.rend()

const int maxn = 1e5 + 42;

void fail() {
    cout << "NO" << endl;
    exit(0);
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int l[n], r[n];
    for(int i = 0; i < n; i++) {
        cin >> l[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> r[i];
    }
    int a[n];
    fill(a, a + n, 0);
    for(int z = 1; z <= n; z++) {
        int mx = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] == 0) {
                mx = max(mx, l[i] + r[i]);
            }
        }
        for(int i = 0; i < n; i++) {
            if(l[i] + r[i] == mx) {
                a[i] = z;
            }
        }
    }
    
    for(int i = 0; i < n; i++) {
        int L = 0, R = 0;
        for(int j = 0; j < i; j++) {
            if(a[i] < a[j]) {
                L++;
            }
        }
        for(int j = i + 1; j < n; j++) {
            if(a[i] < a[j]) {
                R++;
            }
        }
        if(L != l[i] || R != r[i]) {
            fail();
        }
    }
    cout << "YES" << endl;
    for(auto it: a) {
        cout << it << ' ';
    }
    return 0;
}