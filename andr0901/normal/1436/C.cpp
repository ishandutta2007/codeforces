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

int cnt_less = 0, cnt_greater = 0;

int bin_search(int l, int r, int pos) {
    cerr << l << " " << r << "\n";
    if (!(l < r))
        return 0;
    int m = (l + r) / 2;
    if (pos < m) {
        ++cnt_less;
        cerr << "less: " << m << "\n";
        return 1 + bin_search(l, m, pos);
    } else {
        if (pos != m)
            cnt_greater++;
        cerr << "greater: " << m << "\n";
        return 1 + bin_search(m + 1, r, pos);
    }
}

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
    int n, x, pos;
    cin >> n >> x >> pos;
    int cnt = bin_search(0, n, pos);
    int greater = (n - x), less = x - 1;
    int remain = n - 1 - cnt_greater - cnt_less;
    swap(cnt_greater, cnt_less);
    cerr << cnt_greater << " " << cnt_less << " " << remain << "\n\n";
    int ans = 1;
    forn (i, 0, cnt_greater) {
        ans = mul(ans, greater);
        --greater;
    }
    forn (i, 0, cnt_less) {
        ans = mul(ans, less);
        --less;
    }
    cerr << ans << "\n";
    forn (i, 0, n - 1 - cnt_greater - cnt_less) {
        ans = mul(ans, remain);
        --remain;
    }
    cout << ans;
    return 0;
}