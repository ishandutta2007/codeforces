#include <bits/stdc++.h>
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("vpt")
#endif

using namespace std;

typedef long long ll;
typedef long double ld;

const char el = '\n';
const int inf = 1e9;
const ll llinf = 1e18, mod = 1000'000'007;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define firn(i, n) for (int i = 1; i < (int)n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define x first
#define y second
#define debug(x) cout << #x << ": " << x << el

template<typename T> bool uin(T &a, T b) { if (b < a) { a = b; return 1; } return 0; }
template<typename T> bool uax(T &a, T b) { if (b > a) { a = b; return 1; } return 0; }
template<class iterator> void output(iterator begin, iterator end, char p = ' ', ostream & out = cout) { while (begin != end) { out << (*begin) << p; begin++; } out << el; }
template<class T> void output(T x, char p = ' ', ostream & out = cout) { output(all(x), p, out); }

mt19937 rnd(time(NULL));
#define int ll
vector<int> a, cnt;
int h, g;
int c;
int solve(int i, int k = 0) {
    cnt[i]--;
    int tmp;
    if (a[i + i] == 0 && a[i + i + 1] == 0) {
        tmp = a[i];
        a[i] = 0;
        c = i;
        return tmp;
    }
    if (a[i + i] > a[i + i + 1]) {
        if (k >= g - 1 || cnt[i + i] > (1 << (g - k - 1)) - 1) {
            tmp = a[i];
            a[i] = solve(i + i, k + 1);
            if (!a[i]) swap(a[i], tmp);
            else c = i;
            return tmp;
        }
        solve(i + i + 1, k + 1);
        return 0;
    }
    if (k >= g - 1 || cnt[i + i + 1] > (1 << (g - k - 1)) - 1) {
        tmp = a[i];
        a[i] = solve(i + i + 1, k + 1);
        if (!a[i]) swap(a[i], tmp);
        else c = i;
        return tmp;
    }
    solve(i + i, k + 1);
    return 0;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        cin >> h >> g;
        int n = (1 << h) - 1;
        a.assign((1 << (h + 1)) + 1, 0);
        cnt.assign((1 << (h + 1)) + 1, 0);
        firn(i, n + 1) cin >> a[i];
        vector<int> v;
        for (int i = n; i > 0; i--) cnt[i] = 1 + cnt[i + i] + cnt[i + i + 1];
        forn(i, (1 << h) - (1 << g)) {
            solve(1);
            v.push_back(c);
        }
        ll sum = 0;
        firn(i, n) sum += a[i];
        cout << sum << el;
        forn(i, (1 << h) - (1 << g)) cout << v[i] << ' ';
        cout << el;
    }
    return 0;
}