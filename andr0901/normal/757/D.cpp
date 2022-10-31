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


constexpr int N = 75, M = 20;

int dp[N + 2][1 << M];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    auto get = [&](int l, int r) {
        int ans = 0;
        for (int i = r, p = 0; i >= l; --i, ++p) {
            if (s[i] == '1' && p > 6)
                return -1;
            ans += ((s[i] - '0') << p);
        }
        return ans;
    };
    forn (i, 0, N + 2)
        forn (j, 0, 1 << M)
            dp[i][j] = 0;
    dp[0][0] = 1;
    forn (i, 1, n + 1) {
        dp[i][0] = 1;
        int idx = i - 1;
        for (int j = max(0, idx - N); j <= idx; ++j) {
            int num = get(j, idx);
            --num;
            if (!(0 <= num && num < M))
                continue;
            forn (prev_mask, 0, 1 << M) {
                dp[i][prev_mask | (1 << num)] = add(dp[i][prev_mask | (1 << num)], dp[j][prev_mask]);
            }
        }
    }
    int ans = 0;
    forn (i, 0, n + 2) {
        int cur = 0;
        forn (j, 0, M) {
            cur += (1 << j);
            ans = add(ans, dp[i][cur]);
        }
    }
    cout << ans << "\n";
    return 0;
}