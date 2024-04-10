#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
const int MN = 1000005;
int n, a[MN], inv[MN], bit[MN][2]; ll ans; map<int, int> mp; vector<int> v;
void upd(int x, int val, int t) {for (int i = x; i < MN; i += i & -i) bit[i][t] += val;}
int qry(int x, int t) {int ret = 0; for (int i = x; i > 0; i -= i & -i) ret += bit[i][t]; return ret;}
int tot(int t) {return qry(MN - 1, t);}
int32_t main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], v.push_back(a[i]);
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) mp[v[i]] = i + 1;
    for (int i = 1; i <= n; i++) {
        a[i] = mp[a[i]];
        inv[i] = tot(0) - qry(a[i], 0);
        ans += tot(1) - qry(a[i], 1);
        upd(a[i], 1, 0);
        upd(a[i], inv[i], 1);
    }
    printf("%lld\n", ans);
}