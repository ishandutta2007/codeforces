#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tt;
    cin >> tt;
    while (tt--) {
        vector<int> a;
        vector<int> b;
        int n;
        cin >> n;
        for (int i = 0; i < 2 * n; i++) {
            int x, y;
            cin >> x >> y;
            if (x == 0) b.push_back(abs(y));
            else a.push_back(abs(x));
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        long double res = 0;
        for (int i = 0; i < n; i++) {
            res += sqrt((long double) a[i] * a[i] + (long double) b[i] * b[i]);
        }
        cout << setprecision(12) << fixed << res << '\n';
    }

    return 0;
}