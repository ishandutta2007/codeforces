#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int maxn = 1e5 + 42;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int a[k];
    int A = 0, B = 0;
    bool A3 = 0, B3 = 0;
    for(int i = 0; i < k; i++) {
        cin >> a[i];
        int tA = a[i] / n;
        int tB = a[i] / m;
        if(tA >= 2) {
            A += tA;
            A3 |= tA >= 3;
        }
        if(tB >= 2) {
            B += tB;
            B3 |= tB >= 3;
        }
    }
    A3 |= m % 2 == 0;
    B3 |= n % 2 == 0;
    if((A3 && A >= m) || (B3 && B >= n)) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
    
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}