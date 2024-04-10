#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, m, k;
int a[maxn], b[maxn], c[maxn];
ll ans;
ll sqr(ll x) {
    return x * x;
}
void upd(int x, int y, int z) {
    if(x < 0 || y < 0 || z < 0) return;
    if(x == n || y == m || z == k) return;
    ans = min(ans, sqr(a[x] - b[y]) + sqr(a[x]-c[z]) + sqr(b[y] - c[z]));
}
void solve() {
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }
    for(int i = 0 ; i < k; i++) {
        scanf("%d", &c[i]);
    }
    sort(a, a + n);
    sort(b, b + m);
    sort(c, c + k);
    ans = 4e18;
    for(int i = 0; i < n; i++) {
        int x = lower_bound(b, b + m, a[i]) - b;
        int y = lower_bound(c, c + k, a[i]) - c;
        upd(i, x, y);
        upd(i, x-1, y);
        upd(i, x, y-1);
        upd(i, x-1, y-1);
    }
    for(int i = 0; i < m; i++) {
        int x = lower_bound(a, a + n, b[i]) - a;
        int y = lower_bound(c, c + k, b[i]) - c;
        upd(x, i, y);
        upd(x-1, i, y);
        upd(x, i, y-1);
        upd(x-1, i, y-1);
    }
    for(int i = 0; i < k; i++) {
        int x = lower_bound(a, a + n, c[i]) - a;
        int y = lower_bound(b, b + m, c[i]) - b;
        upd(x, y, i);
        upd(x-1, y, i);
        upd(x, y-1, i);
        upd(x-1, y-1, i);
    }
    cout << ans << "\n";
}

int main() {
    int t = 1;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}


#pragma clang diagnostic pop