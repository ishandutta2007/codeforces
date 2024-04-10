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
    int n, k, x, tmp, pre, count = 1;
    cin >> n >> k >> x;
    vector <pii> aa;
    cin >> pre;
    fop (i,1,n) {
        cin >> tmp;
        if (pre == tmp) count++;
        else {
            aa.eb(pre, count);
            pre = tmp;
            count = 1;
        }
    }
    aa.eb(pre, count);
    int ans = 0;
    fop (i,0,aa.size()) {
        if (aa[i].X == x) {
            int tmp = aa[i].Y, l = i - 1, r = i + 1;
            if (tmp == 1) {
                continue;
            }
            while (l >= 0 and r < aa.size()) {
                if (aa[l].X == aa[r].X and aa[l].Y + aa[r].Y >= 3) {
                    tmp += aa[l].Y + aa[r].Y;
                    l--; r++;
                } else {
                    break;
                }
            }
            ans = max(ans, tmp);
        }
    }
    cout << ans << endl;
}