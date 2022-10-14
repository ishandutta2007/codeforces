#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()

const int INF = 1e9 + 1;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    if (m == 0) {
        cout << 1;
        return 0;
    }
    vector <int> a(n, 1);
    int cnt = 0;
    for (int i = 0; i < n && cnt < m; i += 2) {
        a[i] = 0;
        cnt++;
    }
    for (int i = 0; i < n && cnt < m; i++) {
        if (a[i] == 1) {
            a[i] = 0;
            cnt++;
        }
    }
    bool f = false;
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] == 1 && f == false) {
            f = true;
            continue;
        }
        if (a[i] == 0 && f == false) {
            continue;
        }
        if (a[i] == 1 && f == true) {
            continue;
        }
        ans++;
        f = false;
    }
    if (f == true) {
        ans++;
    }
    cout << ans;
    return 0;
}