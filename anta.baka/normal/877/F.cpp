#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1e5;
const int SZ = 317;

int n, k, q;
ll a[maxn + 1];
map<ll, int> x;
int amk[maxn + 1], ak[maxn + 1], apk[maxn + 1];

struct query {
    int l, r, id;
    bool operator < (const query &z) const {
        return l / SZ < z.l / SZ || l / SZ == z.l / SZ && r < z.r;
    }
} qs[maxn];

int cnt[3 * maxn];
ll ans[maxn], cur;
int L, R;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) {
        int x; cin >> x; a[i] = (a[i] == 1 ? x : -x);
    }
    partial_sum(a, a + n + 1, a);
    for(int i = 0; i <= n; i++) {
        x[a[i] - k];
        x[a[i]];
        x[a[i] + k];
    }
    int tmp = 0;
    for(auto it = x.begin(); it != x.end(); it++) it->second = tmp++;
    for(int i = 0; i <= n; i++) {
        amk[i] = x[a[i] - k];
        ak[i] = x[a[i]];
        apk[i] = x[a[i] + k];
    }
    cin >> q;
    for(int i = 0; i < q; i++) {
        cin >> qs[i].l >> qs[i].r; qs[i].id = i;
        qs[i].l--;
    }
    sort(qs, qs + q);
    cnt[ak[0]] = 1;
    for(int i = 0; i < q; i++) {
        while(L > qs[i].l) {
            L--;
            cur += cnt[apk[L]];
            cnt[ak[L]]++;
        }
        while(R < qs[i].r) {
            R++;
            cur += cnt[amk[R]];
            cnt[ak[R]]++;
        }
        while(L < qs[i].l) {
            cnt[ak[L]]--;
            cur -= cnt[apk[L]];
            L++;
        }
        while(R > qs[i].r) {
            cnt[ak[R]]--;
            cur -= cnt[amk[R]];
            R--;
        }
        ans[qs[i].id] = cur;
    }
    for(int i = 0; i < q; i++) cout << ans[i] << '\n';
}