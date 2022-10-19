#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxx = 5000;
const int maxx1 = 2000;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, p;
    cin >> n >> p;
    vector<int> a(n);
    vector<int> kol(maxx + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++kol[a[i]];
    }
    for (int i = 1; i <= maxx; ++i) kol[i] += kol[i - 1];
    vector<int> ans;
    for (int x = 1; x <= maxx1; ++x) {
        int now = 1;
        for (int i = 0; i < n; ++i) {
            now *= (kol[x + i] - i);
            now %= p;
        }
        if (now != 0) ans.push_back(x);
    }
    cout << ans.size() << "\n";
    for (int i : ans) cout << i << " ";
}