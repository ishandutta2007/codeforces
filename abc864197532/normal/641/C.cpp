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
    int n, q, x, y;
    cin >> n >> q;
    int count = 0;
    lli aa = 0, bb = 0, all = 0; // even odd
    while (q--) {
        cin >> x;
        if (x == 1) {
            cin >> y;
            if (abs(y) == n) continue;
            if (y < 0) y += n;
            int k = (all + count) & 1;
            aa += ((y + k) / 2);
            bb += ((y + !k) / 2);
            all += y;
        } else {
            count ^= 1;
        }
    }
    int ans[n];
    for (int i = 0; i < n; i += 2) {
        lli tmp = (aa * 2 + i) % n;
        if (tmp < 0) tmp += n;
        ans[tmp] = i;
    }
    for (int i = 1; i < n; i += 2) {
        lli tmp = (bb * 2 + i) % n;
        if (tmp < 0) tmp += n;
        ans[tmp] = i;
    }
    if ((all + count) & 1) fop (i,0,n/2) swap(ans[i * 2], ans[i * 2 + 1]); 
    fop (i,0,n) {
        cout << ans[i] + 1 << " \n"[i == n - 1]; 
    }
}