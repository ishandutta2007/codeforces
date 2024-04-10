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
    int x, y;
    cin >> x >> y;
    int ans = 1000;
    fop (i,0,1000) {
        if (y == i and -i <= x and x <= i) {
            ans = min(ans, 4 * i - 2);
        }
        if (x == -i and -i <= y and y <= i) {
            ans = min(ans, 4 * i - 1);
        }
    }
    fop (i,0,1000) {
        if (y == -i and -i <= x and x <= i + 1) {
            ans = min(ans, 4 * i);
        }
        if (x == i + 1 and -i <= y and y <= i + 1) {
            ans = min(ans, 4 * i + 1);
        }
    }
    cout << max(ans, 0) << endl;
}