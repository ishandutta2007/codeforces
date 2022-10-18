#include <bits/extc++.h>

using namespace std;

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n + 1];
    const int maxk = 31;
    int last[maxk] = {0};
    map<int, int> lpos;
    int64_t ans = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        lpos[a[i]] = i;
        for(int j = 0; j < maxk; j++) {
            if((a[i] >> j) & 1) {
                last[j] = i;
            }
        }
        int p[maxk];
        iota(p, p + maxk, 0);
        sort(p, p + maxk, [&](int a, int b) {
           return last[a] > last[b]; 
        });
        int cur = 0;
        for(int i = 0; i < maxk; i++) {
            while(i + 1 < maxk && last[p[i + 1]] == last[p[i]]) {
                cur |= 1 << p[i++];
            }
            cur |= 1 << p[i];
            int nxpos = i + 1 == maxk ? 0 : last[p[i + 1]];
            ans += max((int)0, last[p[i]] - max(nxpos, lpos[cur]));
        }
    }
    cout << ans << endl;
    return 0;
}