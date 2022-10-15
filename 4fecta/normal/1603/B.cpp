#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 100005;

int x, y;

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        cin >> x >> y;
        if (x > y) printf("%lld\n", x + y);
        else if (x == y) printf("%lld\n", x);
        else {
            /*int X = x, Y = y;
            while (1) {
                int n = (x + y) / 2;
                int xx = n % X, yy = Y % n;
                if (xx == yy) {printf("%lld\n", n); printf("%lld %lld\n", n % X, Y % n); break;}
                x = xx, y = yy;
            }*/
            //for (int n = x; n <= y; n++) printf("%lld %lld %lld\n", n, n % x, y % n);
            int d = y % x;
            int n = y - d / 2;
            printf("%lld\n", n);
        }
    }

    return 0;
}