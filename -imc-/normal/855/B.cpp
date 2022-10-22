#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;

//#define int li

void solve(bool read) {
    const li INF = 4e18 + 100;
    
    int n;
    li p, q, r;
    cin >> n >> p >> q >> r;
    
    vector<li> a(n), ap(n), ar(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ap[i] = max(i ? ap[i - 1] : -INF, a[i] * p);
        ar[i] = a[i] * r;
    }
    
    for (int i = n - 1; i >= 0; i--)
        ar[i] = max(i + 1 < n ? ar[i + 1] : -INF, ar[i]);
    
    li answer = -INF;
    for (int i = 0; i < n; i++) {
        answer = max(answer, a[i] * q + ap[i] + ar[i]);
    }
    
    cout << answer << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int nt = 1;
    //cin >> nt;
    for (int i = 0; i < nt; i++)
        solve(true);
    
#if 0
    while (true) {
        guessed = false;
        solve(false);
        assert(guessed);
    }
#endif
    
    return 0;
}