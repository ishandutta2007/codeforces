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

void solve() {
    lli n;
    int m, tmp;
    cin >> n >> m;
    lli all = 0;
    bool a[63];
    int b[63];
    fop (i,0,63) {
        if (n & (1ll << i)) a[i] = true;
        else a[i] = false;
        b[i] = 0;
    }
    fop (i,0,m) {
        cin >> tmp;
        all += tmp;
        int cnt = 0;
        while (tmp > 1) {
            tmp >>= 1;
            cnt++;
        }
        b[cnt]++;
    }
    if (n > all) {
        cout << -1 << endl;
        return;
    }
    int ans = 0;
    fop (i,0,63) {
        if (a[i]) {
            int p;
            fop (j,i,63) {
                if (b[j] > 0) {
                    p = j;
                    break;
                }
            }
            b[p]--;
            while (p > i) {
                p--;
                b[p]++;
                ans++;
            }
        }
        if (i < 62) b[i+1] += b[i] / 2;
    }
    cout << ans << endl;
}

int main () {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}