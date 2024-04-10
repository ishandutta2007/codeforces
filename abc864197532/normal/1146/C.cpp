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
    int t;
    cin >> t;
    while (t--) {
        int n, ans = 0, tmp;
        cin >> n;
        cout << 1 << ' ' << n - 1 << ' ';
        fop (i,1,n+1) cout << i << ' ';
        cout << endl;
        cin >> ans;
        fflush(stdout);
        int l = 2, r = n + 1;
        while (r - l > 1) {
            int m = l + r >> 1;
            cout << 1 << ' ' << m - l << ' ' << 1 << ' ';
            fop (i,l,m) cout << i << ' ';
            cout << '\n';
            cin >> tmp;
            fflush(stdout);
            if (ans == tmp) r = m;
            else l = m;
        }
        cout << 1 << ' ' << n - 1 << ' ' << l << ' ';
        fop (i,1,n+1) {
            if (i == l) continue;
            cout << i << ' ';
        }
        cout << '\n';
        cin >> ans;
        fflush(stdout);
        cout << -1 << ' ' << ans << endl;
    }
}