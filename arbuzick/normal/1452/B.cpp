#include <bits/stdc++.h>
#define int long long
#define double long double
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        int s = 0;
        for (int i = 0; i < n; ++i)
            s += a[i];
        int l = -1, r = 100000000000LL;
        while (l < r-1) {
            int m = (l+r)/2;
            bool ans = 1;
            for (int i = 0; i < n; ++i)
                if (a[i] > m)
                    ans = 0;
            if (ans && m*(n-1) >= s)
                r = m;
            else
                l = m;
        }
        cout << r*(n-1)-s << '\n';
    }
    return 0;
}