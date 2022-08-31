#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fc first
#define sc second
#define ll long long
#define forn(i, n) for (int i = 0; i < (int) (n); i++)
#define fort(i, j, n) for (int i = j; i < (int) (n); i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define bit(x) __builtin_popcount(x)

const int N = 1048576;
const int MAXN = (int) 1e6 + 7;
const int INF = (int) 1e9 + 7;
int t[2 * N + 7];
int fenw[2 * N + 7];
int a[N];
int b[N];
int c[N];
bool used[N];

int get(int p) {
    int c = 0;
    for (; p >= 0; p = (p & (p + 1)) - 1) {
        c += fenw[p];
    }
    return c;
}

void inc(int p) {
    for (; p < N; p = (p | (p + 1))) {
        fenw[p]++;
    }
}

int got(int l, int r) {
    return get(r) - get(l - 1);
}

int main() {
    vector <pair <int, int> > e, f;
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        f.pb({a[i], i});
    }
    for (int i = 0; i < k; i++) {
        scanf("%d", &b[i]);
        used[b[i]] = 1;
    }
    for (int i = 0; i < n; i++) {
        if (!used[a[i]]) {
            e.pb({a[i], i});
        }
    }
    ll ans = 0;
    sort(all(f));
    set <int> pos;
    for (int i = 0; i < n; i++) {
        if (!used[f[i].fc]) {
            auto it = pos.upper_bound(f[i].sc);
            int r = (it == pos.end() ? n - 1 : *it - 1);
            int l = (it == pos.begin() ? 0 : *(--it) + 1);
            ans += r - l + 1 - got(l, r); 
            inc(f[i].sc);
        } else {
            pos.insert(f[i].sc);
        }
    }
    printf("%lld\n", ans);
}