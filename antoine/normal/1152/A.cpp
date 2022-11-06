#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;


int a[2], b[2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++a[x & 1];
    }
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        ++b[x & 1];
    }

    int ans = min(a[0], b[1]) + min(a[1], b[0]);
    cout << ans;
    return 0;
}