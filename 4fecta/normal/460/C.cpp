#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MN = 100005;
int n, m, w, a[MN], bit[3 * MN];
void upd(int x, int val) {if (x < 1) {return;} for (int i = x; i < MN * 3; i += i & -i) bit[i] += val;}
int qry(int x) {int ret = 0; for (int i = x; i > 0; i -= i & -i) ret += bit[i]; return ret;}
int getval(int x) {return qry(x) - qry(x - 1);}
bool check(int low) {
    memset(bit, 0, sizeof(bit));
    for (int i = 1; i <= n; i++) {
        upd(i, low - a[i] - qry(i - 1));
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int num = qry(i);
        if (num > 0) {
            ans += num;
            upd(i, -num);
            upd(i + w, num);
        }
    }
    return ans <= m;
}
int32_t main() {
    cin.tie(0), cin.sync_with_stdio(0);
    cin >> n >> m >> w;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int lo = 1, hi = INT_MAX, mid;
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        mid += (lo + hi) & 1;
        if (check(mid)) lo = mid;
        else hi = mid - 1;
    }
    printf("%lld\n", lo);
}