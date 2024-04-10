#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define X first
#define Y second

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d, x, y, x0, y0, x1, y1;
        cin >> a >> b >> c >> d >> x >> y >> x0 >> y0 >> x1 >> y1;
        bool is = true;
        if (x0 == x and x == x1 and (a != 0 or b != 0)) is = false;
        if (y0 == y and y == y1 and (c != 0 or d != 0)) is = false;
        if (a > x - x0) {
            a -= (x - x0);
            x = x0;
            b -= a;
            if (b < 0 or b > x1 - x0) is = false;
        } else {
            x -= a;
            if (b > x1 - x) is = false;
        }
        if (c > y - y0) {
            c -= (y - y0);
            y = y0;
            d -= c;
            if (d < 0 or d > y1 - y0) is = false;
        } else {
            y -= c;
            if (d > y1 - y) is = false;
        }
        cout << (is ? "Yes" : "No") << endl;
    }
}