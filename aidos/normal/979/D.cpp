#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, m;
int u[maxn];
int nxt[maxn * 200][2];
int sz = 0;
int st[maxn];
int a[maxn * 200];
void add2(int d, int x) {
    int cur = st[d];
    a[cur] = min(a[cur], x);
    for(int i = 18; i >= 0; i--) {
        int bit = (x&(1<<i)) > 0;
        if(nxt[cur][bit] == 0) {
            nxt[cur][bit] = ++sz;
            a[sz] = inf;
        }
        cur = nxt[cur][bit];
        a[cur] = min(a[cur], x);
    }
}
void add(int x) {
    if(u[x]) return;
    u[x] = 1;
    for(int i = 1; i * i <= x; i++) {
        if(x % i == 0) {
            add2(i, x);
            add2(x/i, x);
        }
    }
}
int get(int x, int k, int s) {
    int cur = st[k];
    if(x % k != 0 || a[cur] + x > s) return -1;
    int val = 0;
    for(int i = 18; i >= 0; i--) {
        int bit = (x&(1<<i)) > 0;
        if(nxt[cur][bit^1] > 0 && a[nxt[cur][bit^1]] + x <= s) {
            cur = nxt[cur][bit^1];
        } else {
            cur = nxt[cur][bit];
        }
        if(cur == 0) {
            assert(false);
        }
    }
    return a[cur];
}
void solve() {
    for(int i = 1; i < maxn; i++) {
        st[i] = ++sz;
        a[sz] = inf;
    }
    cin >> n;
    for(int i = 1; i <= n; i++) {

        int t;
        cin>>t;
        if(t == 1) {
            int x;
            cin >> x;
            add(x);
        } else {
            int x, k, s;
            cin >> x >> k >> s;
            cout << get(x, k, s) << "\n";
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
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