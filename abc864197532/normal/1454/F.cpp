#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<lli,lli>
#define ld long double;
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 200004, logN = 18, K = 500, C = 100;

int StMn[N][logN], StMx[N][logN];

int queryMn(int l, int r) {
    if (r == l) return 1 << 30;
    int g = __lg(r - l);
    return min(StMn[l][g], StMn[r - (1 << g)][g]);
}

int queryMx(int l, int r) {
    if (r == l) return -1;
    int g = __lg(r - l);
    return max(StMx[l][g], StMx[r - (1 << g)][g]);
}

void solve() {
    int n;
    cin >> n;
    vector <int> a(n), v(n);
    fop (i,0,n) cin >> a[i], v[i] = a[i];
    sort(all(v));
    v.resize(unique(all(v)) - v.begin());
    vector <int> cnt[v.size()];
    fop (i,0,n) a[i] = lower_bound(all(v), a[i]) - v.begin(), cnt[a[i]].pb(i), StMn[i][0] = StMx[i][0] = a[i];
    auto buildSt = [&](){
        for (int j = 1; j < logN; ++j) {
            for (int i = 0; i + (1 << j) <= n; ++i) {
                StMn[i][j] = min(StMn[i][j - 1], StMn[i + (1 << j - 1)][j - 1]);
                StMx[i][j] = max(StMx[i][j - 1], StMx[i + (1 << j - 1)][j - 1]);
            }
        }
    };
    buildSt();
    int l = n, r = -1, cnt2 = 0;
    auto check = [&](int l, int r) {
        return queryMx(0, l) == queryMx(r + 1, n) && queryMx(0, l) == queryMn(l, r + 1);
    };
    FOP (i,v.size(),0) {
        if (cnt[i].size() >= 3) {
            if (l == n) {
                cout << "YES\n";
                cout << cnt[i][1] << ' ' << 1 << ' ' << n - cnt[i][1] - 1 << endl;
                return;
            }
            if (r - l + 1 == cnt2) {
                int id = 0;
                fop (j,0,cnt[i].size()) {
                    if (cnt[i][j] < l) id = j;
                }
                if (check(cnt[i][id], r)) {
                    cout << "YES\n";
                    cout << cnt[i][id] << ' ' << r - cnt[i][id] + 1 << ' ' << n - r - 1 << endl;
                    return;
                }
                if (id + 1 < cnt[i].size() && check(l, cnt[i][id + 1])) {
                    cout << "YES\n";
                    cout << l << ' ' << cnt[i][id + 1] - l + 1 << ' ' << n - cnt[i][id + 1] - 1 << endl;
                    return;
                }
            }
            if (check(l, r)) {
                cout << "YES\n";
                cout << l << ' ' << r - l + 1 << ' ' << n - r - 1 << endl;
                return;
            }
        }
        for (int j : cnt[i]) {
            l = min(l, j);
            r = max(r, j);
            cnt2++;
        }
    }
    cout << "NO\n";
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}