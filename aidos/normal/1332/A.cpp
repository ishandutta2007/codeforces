#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = 998244353;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
const double eps = 1e-15;
int n, x;
void solve() {
    int a, b, c, d;
    int x, y, x1, y1, x2, y2;
    cin >> a >> b >> c >> d >> x >> y >> x1 >> y1 >> x2 >> y2;
    int X = b - a + x;
    int Y = d - c + y;
    if(a+b>0&&x1 == x2) {
        cout << "NO\n";
        return;
    }
    if(c + d>0&&y1 == y2) {
        cout << "NO\n";
        return;
    }
    if(X < x1 || X>x2 || Y < y1 || Y > y2) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}