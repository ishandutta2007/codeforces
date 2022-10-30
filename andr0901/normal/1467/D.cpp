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


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, k, q;
    cin >> n >> k >> q;
    vector<vector<int>> dp(n, vector<int> (k + 1));
    forn (i, 0, n)
        dp[i][0] = 1;
    forn (i, 0, k) {
        forn (prev, 0, n) {
            if (prev - 1 >= 0)
                dp[prev - 1][i + 1] = add(dp[prev - 1][i + 1], dp[prev][i]);
            if (prev + 1 < n)
                dp[prev + 1][i + 1] = add(dp[prev + 1][i + 1], dp[prev][i]);
        }
    }
    vector<int> cnt(n);
    forn (i, 0, n) {
        forn (j, 0, k + 1) {
            cnt[i] = add(cnt[i], mul(dp[i][j], dp[i][k - j]));
        }
    }
    vector<int> a(n);
    cin >> a;
    int ans = 0;
    forn (i, 0, n)
        ans = add(ans, mul(cnt[i], a[i]));
    while (q --> 0) {
        int idx, val;
        cin >> idx >> val, --idx;
        ans = sub(ans, mul(cnt[idx], a[idx]));
        a[idx] = val;
        ans = add(ans, mul(cnt[idx], a[idx]));
        cout << ans << "\n";
    }
    return 0;
}