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

const int MOD = 998244353;

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


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    cin >> a;
    vector<int> sums(3e5 + 5);
    int p = 4;
    forn (i, 2, sums.size()) {
        int cur = inv(p);
        sums[i] = sums[i - 1];
        if (i % 2 == 0) {
            sums[i] = add(sums[i], cur);
        } else {
            sums[i] = sub(sums[i], cur);
        }
        p = mul(p, 2); 
    }
    int ans = 0;
    forn (i, 0, n) {
        int cur = 0;
        forn (j, 0, m) {
            if (a[i][j] == 'o') {
                ++cur;
                if (cur >= 2) {
                    ans = add(ans, sums[cur]);
                }
            } else {
                cur = 0;
            }
        }
    }
    forn (j, 0, m) {
        int cur = 0;
        forn (i, 0, n) {
            if (a[i][j] == 'o') {
                ++cur;
                if (cur >= 2) {
                    ans = add(ans, sums[cur]);
                }
            } else {
                cur = 0;
            }
        }
    }
    int s = 0;
    for_each(all(a), [&s](const auto& row) {
        s += count(all(row), 'o');
    });
    cout << mul(ans, bin_pow(2, s));
    return 0;
}