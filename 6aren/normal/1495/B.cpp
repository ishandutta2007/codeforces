#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n + 2);
    vector<int> l(n + 2, 0), r(n + 2, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 2; i <= n; i++) {
        if (a[i] > a[i - 1]) l[i] = l[i - 1] + 1;
        else l[i] = 0;
    }
    for (int i = n - 1; i >= 1; i--) {
        if (a[i] > a[i + 1]) r[i] = r[i + 1] + 1;
        else r[i] = 0;
    }
    int mx = 0;
    for (int i = 1; i <= n; i++) mx = max({mx, l[i], r[i]});
    int cnt = 0;
    int cnt_peak = 0;
    for (int i = 1; i <= n; i++) {
        if (l[i] == mx) cnt++;
        if (r[i] == mx) cnt++;
        if (l[i] == mx && r[i] == mx) cnt_peak++;
    }
    cout << (cnt_peak == 1 && cnt == 2 && (mx % 2 == 0) ? "1\n" : "0\n");

    return 0;
}