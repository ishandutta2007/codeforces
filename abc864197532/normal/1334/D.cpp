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

void solve() {
    int n;
    lli l, r;
    cin >> n >> l >> r;
    l--;
    lli start = 0, now = 2 * (n - 1), aa = 1;
    while (start + now < l) {
        start += now;
        now -= 2;
        aa++;
    }
    now = l - start;
    while (l < r) {
        if (l == 1ll * n * (n - 1)) {
            cout << 1 << ' ';
        } else if (now & 1) {
            cout << aa + (now + 1) / 2 << ' ';
        } else {
            cout << aa << ' ';
        }
        l++;
        now++;
        if (now == 2 * (n - aa)) {
            now = 0;
            aa++;
        }
    }
    cout << '\n';
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}