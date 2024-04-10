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
typedef long double ld;
typedef long long ll;

int a[100100], b[100100];

int main() {
#ifdef LOCAL
    freopen("l.in", "r", stdin);
#endif

    int n, k;
    cin >> n >> k;
    forn(i, n) {
        cin >> a[i];
    }
    forn(i, n) cin >> b[i];
    vector<vi> s(k);
    forn(i, n) s[a[i]-1].push_back(b[i]);
    vi r;
    int cnt = 0;
    forn(i, k) {
        sort(all(s[i]));
        forn(j, s[i].size()-1) r.push_back(s[i][j]);
        if (!s[i].empty()) ++cnt;
    }
    i64 res = 0;
    sort(all(r));
    forn(j, k - cnt) res += r[j];
    cout << res << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}