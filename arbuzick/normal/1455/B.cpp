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
        int x;
        cin >> x;
        int l = 0, r = x;
        while (l < r-1) {
            int m = (l+r)/2;
            if ((m+1)*m/2 >= x)
                r = m;
            else
                l = m;
        }
        if ((r+1)*r/2 == x+1)
            cout << r+1 << '\n';
        else
            cout << r << '\n';
    }
    return 0;
}