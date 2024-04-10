#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

#define double ld
#define pb push_back
#define fir first
#define sec second
#define int long long

const double EPS = 1e-9;
const double INF = 1e18;

signed main() {
    int n;
    cin >> n;

    int big = -1, small;

    for (int i = 2; i * i <= n; i++)
    if (n % i == 0 && __gcd(i, n / i) == 1) {
        big = n / i;
        small = i;
        break;
    }

    if (big == -1) {
        cout << "NO";
        return 0;
    }

    for (int i = 0; i < small; i++) {
        if ((n - 1 - i * big) % small == 0) {
            int a1 = i;
            int a2 = (n - 1 - i * big) / small;
            vector<pair<int, int> > ans;
            if (a1 != 0)
            ans.pb({a1, n / big});
            if (a2 != 0)
            ans.pb({a2, n / small});

            cout << "YES\n";

            cout << ans.size() << '\n';

            for (auto i:ans)
                cout << i.fir << ' ' << i.sec << '\n';
        }
    }
}