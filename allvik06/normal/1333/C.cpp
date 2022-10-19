#include <bits/stdc++.h>

using namespace std;
#define int long long
vector <int> k;
vector <int> t;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int now = 0;
    k.resize(n, n);
    map <int, int> tmp;
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] == 0) {
            k[i] = i;
        }
        else {
            if (tmp.find(-a[i] - now) != tmp.end()) {
                k[i] = tmp[-a[i] - now];
            }
        }
        now += a[i];
        tmp[a[i] - now] = i;
    }
    int ans = 0, r = n - 1;
    for (int i = n - 1; i >= 0; --i) {
        r = min(r, k[i] - 1);
        ans += max(r - i + 1, (int)0);
    }
    cout << ans;
    return 0;
}