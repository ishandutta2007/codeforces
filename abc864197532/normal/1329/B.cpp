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

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int d, m;
        lli ans = 1;
        cin >> d >> m;
        d++;
        fop (i,0,30) {
            if ((1 << i) <= d) {
                ans = ans * (min(1 << (i + 1), d) - (1 << i) + 1) % m;
            }
        }
        ans = (ans - 1 + m) % m;
        cout << ans << '\n';
    }
}