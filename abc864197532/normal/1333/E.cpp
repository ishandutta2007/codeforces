#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<lli,lli>
#define X first
#define Y second

int a[3][3] = {{9, 5, 6}, {7, 2, 8}, {1, 3, 4}};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    if (n <= 2) {
        cout << -1 << endl;
        return 0;
    }
    int ans[n][n];
    int now = n, tmp = 1;
    while (now > 3) {
        if (now & 1) {
            fop (i,0,now) ans[now - 1][i] = tmp++;
            FOP (i,now - 1,0) ans[i][now - 1] = tmp++;
        } else {
            fop (i,0,now) ans[i][now - 1] = tmp++;
            FOP (i,now - 1,0) ans[now - 1][i] = tmp++;
        }
        now--;
    }
    fop (i,0,3) fop (j,0,3) ans[i][j] = a[i][j] + n * n - 9;
    fop (i,0,n) fop (j,0,n) cout << ans[i][j] << " \n"[j == n - 1];
}