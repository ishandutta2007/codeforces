#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)1e6+100;
int n, m;
int t[maxn];
int p[maxn];
int u[maxn];
int get(int pos) {
    int res = 0;
    for(int i = pos; i >= 0; i = (i & (i + 1)) - 1) {
        res += t[i];
    }
    return res;
}
void upd(int pos, int val) {
    for(int i = pos; i <= n; i |= i + 1) {
        t[i] += val;
    }
}
set<int> s1, s2;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cin >> n >> m;

    for(int i = 1, x; i <= n; i++) {
        cin >> x;
        p[x] = i;
    }
    for(int i = 1, x; i <= m; i++) {
        cin >> x;
        u[x] = 1;
    }
    s1.insert(0);
    s1.insert(n + 1);
    long long ans = 0;
    for(int i = 1; i <= n; i++) {
        if(u[i]) {
            s1.insert(p[i]);
        } else {
            auto it = s1.lower_bound(p[i]);
            int r = *it;
            int l = *(--it);
            ans += r - l - 1;
            ans -= get(r-1) - get(l);
            upd(p[i], 1);
        }
    }
    cout << ans << "\n";
    return 0;
}