#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 1e9 + 10;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, kol = 1;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        int sum1 = a[0], sum2 = 0, i = 1, j = n - 1, last1 = a[0], last2 = 0;
        while (j >=     i) {
            last2 = 0;
            bool flag = false;
            while (j >= i && last2 <= last1) {
                last2 += a[j];
                --j;
                flag = true;
            }
            if (flag) {
                ++kol;
            }
            flag = false;
            sum2 += last2;
            last1 = 0;
            while (j >= i && last1 <= last2) {
                last1 += a[i];
                ++i;
                flag = true;
            }
            if (flag) {
                ++kol;
            }
            sum1 += last1;
        }
        cout << kol << " " << sum1 << " " << sum2 << "\n";
    }
    return 0;
}