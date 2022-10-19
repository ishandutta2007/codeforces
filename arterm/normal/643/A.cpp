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
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;

const int maxn = 5050;

int n;
int res[maxn];
int a[maxn];
pii best;
int cnt[maxn];

int main() {
#ifdef LOCAL
    freopen("a.in", "r", stdin);
#endif

    scanf("%d", &n);
    forn(i, n) scanf("%d", &a[i]);
    forn(i, n) {
        forn(j, n+1) cnt[j] = 0;
        best = {-1, -1};
        for (int j = i; j < n; ++j) {
            ++cnt[a[j]];
            best = max(best, pii(cnt[a[j]], -a[j]));
//             cerr << best.fi << " " << -best.se << endl;
            ++res[-best.se];
        }
    }
    forn(i, n) cout << res[i+1] << " "; cout << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}