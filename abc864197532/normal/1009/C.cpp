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
    lli n, m, x, d;
    cin >> n >> m;
    lli k = (n - 1) / 2;
    long double ans = 0;
    fop (i,0,m) {
        cin >> x >> d;
        if (d > 0) {
            ans += n * (n - 1) / 2 * d + x * n;
        } else {
            ans += k * (k + 1) / 2 * d + ((n - k - 1) * (n - k) / 2 * d) + x * n;
        }
    }
    cout << fixed << setprecision(10) << ans / n << endl;
}