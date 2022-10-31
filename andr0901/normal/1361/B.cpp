//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

//vector string deque break continue
#define forn(i, s, f) for (int i = (int)s; i < (int)f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pf push_front
#define pb push_back
#define pop_f pop_front
#define pop_b pop_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

#ifdef DEBUG
#else
    #define cerr if (false) cerr
#endif

template <typename T> istream& operator>>(istream& in, vector <T>& a) {for (auto& i : a) in >> i; return in;}
template <typename T> ostream& operator<<(ostream& out, vector <T>& a)  {for (auto& i : a) out << i << " "; return out;}
template <typename T, typename U> void chkmin(T& a, U b) {if (a > b) a = b;}
template <typename T, typename U> void chkmax(T& a, U b) {if (a < b) a = b;}

const int MOD = 1e9 + 7;

int add(int x, int y) {
    x += y;
    if (x >= MOD)
        return x - MOD;
    return x;
}

int sub(int x, int y) {
    x -= y;
    if (x < 0)
        return x + MOD;
    return x;
}

int mul(int x, int y) {
    return (1LL * x * y) % MOD;
}

int bin_pow(int a, int p) {
    if (!p)
        return 1;
    if (p % 2)
        return (1LL * bin_pow(a, p - 1) * a) % MOD;
    int t = bin_pow(a, p / 2);
    return (1LL * t * t) % MOD;
}

int inv(int x) {
    return bin_pow(x, MOD - 2);
}

const int N = 1e6 + 5;

void solve() {
    int n, p;
    cin >> n >> p;
    vector <int> a(n);
    cin >> a;
    if (p == 1) {
        cout << n % 2 << "\n";
        return;
    }
    map <int, int> cnt;
    forn (i, 0, n)
        cnt[a[i]]++;
    for (auto i = cnt.rbegin(); i != cnt.rend(); ++i) {
        int x = i->fs, y = i->sc;
        if (y % 2 == 0)
            continue;
        bool ok = false;
        long long needed = p;
        forn (j, 1, 100) {
            if (needed >= n)
                break;
            int k = x - j;
            if (cnt.find(k) == cnt.end()) {
                needed *= p;
                continue;
            }
            needed -= cnt[k];
            if (needed <= 0) {
                ok = true;
                break;
            }
            needed *= p;
        }
         /*       for (auto j : cnt)
            cerr << j.fs << " " << j.sc << "\n";*/

        //cerr << x << " " << y << " " << ok << "\n";
        if (ok) {
            needed = p;
            forn (j, 1, 100) {
                if (needed >= n)
                    break;
                int k = x - j;
                if (cnt.find(k) == cnt.end()) {
                    needed *= p;
                    continue;
                }
                long long t = min(needed, 1LL * cnt[k]);
                cnt[k] -= t;
                needed -= t;
                if (needed <= 0)
                    break;
                needed *= p;
            }
        } else {
            cerr << "kek " << x << " " << y << "\n";;
            int s = bin_pow(p, x);
            auto j = ++i;
            for (; j != cnt.rend(); ++j)
                s = sub(s, mul(j->sc, bin_pow(p, j->fs)));
            cout << s << "\n";
            return;
        }
    }
    cout << "0\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}