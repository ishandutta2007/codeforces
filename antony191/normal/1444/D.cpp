#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("vpt")
//#pragma GCC optimize("no-stack-protector")
//#pragma GCC optimize("fast-math")
//#pragma GCC optimize("unroll-loops")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = 1e9, mod = 1000'000'007;
const ll llinf = 1e18;
const char el = '\n';
const ld pi = 3.14159265358979;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define firn(i, n) for (int i = 1; i < (int)(n); i++)
#define debug(x) cout << #x << ": " << x << el
#define x first
#define y second

template<typename T> bool uin(T &a, T b) { if (b < a) { a = b; return true; } return false; }
template<typename T> bool uax(T &a, T b) { if (b > a) { a = b; return true; } return false; }
template<class iterator> void output(iterator begin, iterator end, string p = " ", ostream & out = cout) { while (begin != end) { out << (*begin) << p; begin++; } out << el; }
template<class T> void output(T x, string p = " ", ostream & out = cout) { output(all(x), p, out); }

mt19937 rnd(time(nullptr));
const int N = 1000'001;
bool solve(vector<int> &a, vector<int> &x, vector<int> &y) {
    int sum = 0;
    forn(i, a.size()) sum += a[i];
    if (sum & 1) return false;
    sum /= 2;
    vector<bitset<N>> t(a.size() + 1);
    t[0][0] = true;
    forn(i, a.size()) {
        t[i + 1] = t[i] | (t[i] << a[i]);
    }
    if (!t.back()[sum]) return false;
    int i = (int)a.size() - 1;
    while (i >= 0) {
        if (t[i][sum]) {
            y.push_back(a[i]);
        }
        else {
            x.push_back(a[i]);
            sum -= a[i];
        }
        i--;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n), x1, x2;
        forn(i, n) cin >> a[i];
        int m;
        cin >> m;
        vector<int> b(m), y1, y2;
        forn(i, m) cin >> b[i];
        if (n != m) {
            cout << "No" << el;
            continue;
        }
        if (!solve(a, x1, x2)) {
            cout << "No" << el;
            continue;
        }
        if (!solve(b, y1, y2)) {
            cout << "No" << el;
            continue;
        }
        b.clear();
        forn(i, y1.size()) b.push_back(y1[i]);
        forn(i, y2.size()) b.push_back(-y2[i]);
        sort(rall(b));
        sort(all(x1));
        sort(all(x2));
        cout << "Yes" << el;
        int x = 0, y = 0;
        forn(i, x1.size()) {
            y += b[i];
            cout << x << ' ' << y << el;
            x += x1[i];
            cout << x << ' ' << y << el;
        }
        forn(i, x2.size()) {
            y += b[n - 1 - i];
            cout << x << ' ' << y << el;
            x -= x2[i];
            cout << x << ' ' << y << el;
        }
    }
    return 0;
}