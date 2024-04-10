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

int f(int n, int r) {
    if (r == 0) {
        int ans = 0;
        for (int i = 1; i * i <= n; ++i) {
            if (n % i == 0 && __gcd(i, n / i) == 1) {
                ans += 2;
                if (i == n / i) {
                    --ans;
                }
            }
        }
        return ans;
    }
    int ans = 0;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            ans += f(i, r - 1) + f(n / i, r - 1); 
            if (i == n / i) {
                ans -= f(i, r - 1);
            }
        } 
    }
    return ans;
}

const int MOD = 1e9 + 7;;

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


constexpr int R = 1e6 + 9;

vector<vector<int>> p;

void solve() {
    int r, n;
    cin >> r >> n;
    int ans = 1;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            int cnt = 0;
            while (n % i == 0) {
                n /= i;
                ++cnt;
            }
            ans = mul(ans, p[cnt][r]);
        }
    }
    if (n > 1)
        ans = mul(ans, p[1][r]);
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // forn (n, 1, 66) {
    //     forn (r, 0, 10) {
    //         cerr << r << " " << n << ": " << f(n, r) << "\n";
    //     }
    // }
    p.resize(25);
    p[0] = vector<int> (R, 1);
    forn (i, 1, 25) {
        p[i].resize(R);
        p[i][0] = 2;
        forn (j, 1, R)
            p[i][j] = add(p[i - 1][j], p[i][j - 1]);
    }
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}