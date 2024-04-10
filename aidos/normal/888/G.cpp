#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = 998244353;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
int n;
int a[maxn];
ll ans = 0;
int sz = 0;
int b[maxn * 31][2];
void add(int x) {
    int v = 0;
    for(int i = 29; i >= 0; i--) {
        int c = (x & (1<<i)) > 0;
        if(b[v][c] == 0) {
            b[v][c] = sz;
            b[sz][0] = 0;
            b[sz][1] = 0;
            sz++;
        }
        v = b[v][c];
    }
}
int get(int x) {
    int ans = 0;
    int v = 0;
    for(int i = 29; i >= 0; i--) {
        int c = (x & (1<<i)) > 0;
        if(b[v][c]) {
            ans += c * (1 << i);
            v = b[v][c];
        }else {
            ans += (1-c) * (1 << i);
            v = b[v][!c];
        }
    }
    return ans;
}
void rec(int l, int r, int bit) {
    if(bit < 0) return;
    if(l > r) return;
    if((a[l] & (1<<bit)) == (a[r] & (1<<bit))) {
        rec(l, r, bit-1);
        return;
    }
    int pr = r;
    while(pr >= l && (a[pr] & (1<<bit)) > 0) pr--;
    rec(l, pr, bit-1);
    rec(pr+1, r, bit-1);
    int M = 1 << 30;
    sz = 1;
    b[0][0] = 0;
    b[0][1] = 0;
    for(int i = pr + 1; i <= r; i++) {
        add(a[i]);
    }
    for(int i = l; i <= pr; i++) {
        int x = get(a[i]);
        M = min(M, a[i] ^ x);
    }
    ans += M;
}
void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    rec(0, n-1, 30);
    cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}