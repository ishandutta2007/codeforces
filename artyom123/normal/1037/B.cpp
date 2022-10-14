#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define pb emplace_back()
const int INF = 1e9;

int main() {
    int n, s;
    cin >> n >> s;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    long long ans = 0;
    if (a[n / 2] <= s) {
        for (int i = n / 2; i < n; i++) {
            if (a[i] >= s) {
                break;
            }
            ans += s - a[i];
        }
        cout << ans;
    }
    else {
        for (int i = n / 2; i >= 0; i--) {
            if (a[i] <= s) {
                break;
            }
            ans += a[i] - s;
        }
        cout << ans;
    }

    return 0;
}