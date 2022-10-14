#include <bits/stdc++.h>
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    if (a[n - 1] - a[0] == 2) {
        int ans = n;
        int aa = a[0], bb = a[n - 1], cc = (aa + bb) / 2;
        int cnt = 0;
        for (int i = 0; i < n; ++i) cnt += a[i] == cc;
        for (int i = 0, j = n - 1; i <= j; i++, j--) {
            if (a[i] != aa || a[j] != bb) break;
            ans -= 2;
        }
        int ans2 = n - (cnt / 2) * 2;
        if (ans < ans2) {
            cout << ans << endl;
            for (int i = 0, j = n - 1; i <= j; i++, j--) {
                if (a[i] != aa || a[j] != bb) break;
                a[i]++;
                a[j]--;
            }
            for (int i : a) cout << i << ' ';
            cout << endl;
        } else {
            cout << ans2 << endl;
            cnt = (cnt / 2) * 2;
            for (int i : a) {
                if (i == cc && cnt) {
                    cout << cc + (cnt & 1 ? 1 : -1) << ' ';
                    cnt--;
                } else {
                    cout << i << ' ';
                }
            }
            cout << endl;
        }
    } else {
        cout << n << endl;
        for (int i : a) cout << i << ' ';
        cout << endl;
    }
}