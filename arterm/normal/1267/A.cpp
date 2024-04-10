#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef long long i64;
typedef pair<i64, i64> pii;
typedef unsigned long long u64;
typedef long double ld;
typedef long long ll;

const int maxn = 200500;
const i64 inf = 2e18;

int n;
i64 a[maxn], b[maxn], t[maxn];

i64 firstEnd[maxn];

void scan() {
    cin >> n;
    forn(i, n) cin >> a[i] >> b[i] >> t[i];
}

void solve() {
    forn(i, n) firstEnd[i] = a[i] + t[i];

    vi byfe(n);
    iota(all(byfe), 0);
    sort(all(byfe), [](int i, int j) { return firstEnd[i] < firstEnd[j]; });
    byfe.push_back(n);
    firstEnd[n] = inf;
    int pf = 0;

    set<pii> cur;
    i64 time = 0;

    i64 res = 0;

    while (pf < n || !cur.empty()) {
        if (cur.empty()) {
            cur.emplace(t[byfe[pf]], byfe[pf]);
            time = max(time, a[byfe[pf]]);
            ++pf;
        }

        int v = cur.begin()->second;

        if (time + t[v] > b[v]) {
            cur.erase({t[v], v});
            continue;
        }

        if (pf < n && time + t[v] > firstEnd[byfe[pf]]) {
            cur.emplace(t[byfe[pf]], byfe[pf]);
            time = max(time, a[byfe[pf]]);
            ++pf;
            continue;
        }

        i64 end = b[v];
        if (pf < n) end = min(end, firstEnd[byfe[pf]]);
        i64 cnt = (end - time) / t[v];
        assert(cnt > 0);

        // cerr << "take " << cnt << " dicks of len " << t[v] << "\n";
        time += cnt * t[v];
        res += cnt;
    }

    cout << res << "\n";
}

int main() {
#ifdef LOCAL
    freopen("a.in", "r", stdin);
#endif

    scan();
    solve();

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}