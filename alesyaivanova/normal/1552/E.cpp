#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

const int maxn = 109;
int c[maxn * maxn];
int nxt[maxn * maxn][maxn];
int pr[maxn * maxn][maxn];
int n, k;
int cnt[maxn * maxn];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n * k; i++) {
        cin >> c[i];
        c[i]--;
    }
    for (int i = 0; i < n * k; i++) {
        for (int e = 0; e < n; e++) {
            pr[i][e] = (i ? pr[i - 1][e] : -1);
        }
        pr[i][c[i]] = i;
    }
    for (int i = n * k - 1; i >= 0; i--) {
        for (int e = 0; e < n; e++) {
            nxt[i][e] = (i < n * k - 1 ? nxt[i + 1][e] : -1);
        }
        nxt[i][c[i]] = i;
    }
    set<pair<int, pii> > ans;
    set<int> col;
    int i = 0;
    while ((int)ans.size() < n) {
        pii opt(-1, -1);
        for (int e = 0; e < n; e++) {
            if (col.find(e) != col.end())
                continue;
            int l = nxt[i][e];
            if (l == -1 || l == n * k - 1)
                continue;
            int r = nxt[l + 1][e];
            if (r == -1)
                continue;
//            if (ans.find(mp(l, r)) != ans.end()) {
//                l = r;
//                if (r == n * k - 1)
//                    continue;
//                r = nxt[r + 1][e];
//            }
            if (opt.ff == -1 || r < opt.ff) {
                opt = mp(r, e);
            }
        }
        if (opt.ff == -1) {
            break;
        }
        int r = opt.ff;
        int l = pr[opt.ff - 1][opt.ss];
        ans.emplace(opt.ss, mp(l, r));
        col.emplace(opt.ss);
        for (int e = l; e <= r; e++) {
            cnt[e]++;
            if (cnt[e] == (n + (k - 1) - 1) / (k - 1)) {
                i = e + 1;
            }
        }
    }
//    shuffle(all(ans), rnd);
    for (auto u : ans) {
        cout << u.ss.ff + 1 << " " << u.ss.ss + 1 << "\n";
    }
}