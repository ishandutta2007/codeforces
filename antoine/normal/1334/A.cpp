#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

bool f() {
    int n;
    cin >> n;
    vector<int> a(n+1, 0), b(n+1, 0);
    for(int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i];
        a[i] -= b[i];
    }
    return is_sorted(a.begin(), a.end()) && is_sorted(b.begin(), b.end());
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t;
    cin >> t;

    while(t--)
        cout << (f() ? "YES" : "NO") << '\n';
    return 0;
}