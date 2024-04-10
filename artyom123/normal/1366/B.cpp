#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long

const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, x, m;
        cin >> n >> x >> m;
        int ansl = x, ansr = x;
        for (int i = 0; i < m; i++) {
            int l, r;
            cin >> l >> r;
            if (r < ansl) continue;
            if (l > ansr) continue;
            ansl = min(l, ansl);
            ansr = max(r, ansr);
        }
        cout << ansr - ansl + 1 << "\n";
    }
    return 0;
}