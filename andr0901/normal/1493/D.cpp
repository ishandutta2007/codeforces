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

constexpr int N = 2e5 + 5;

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

int ans = 1;

vector<map<int, int>> a;
vector<multiset<int>> p;

int get_mn(int x) {
    if (p[x].size() < a.size())
        return 0;
    else
        return *p[x].begin();
}

void upd(int idx, int x) {
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            int cnt = 0;
            while (x % i == 0) {
                ++cnt;
                x /= i;
            }
            int prev_mn = get_mn(i);
            if (a[idx].find(i) != a[idx].end())
                p[i].erase(p[i].find(a[idx][i]));
            a[idx][i] += cnt;
            p[i].insert(a[idx][i]);
            int nxt_mn = get_mn(i);
            forn (j, 0, nxt_mn - prev_mn)
                ans = mul(ans, i);
        }
    }
    if (x > 1) {
        int i = x;
        int cnt = 1;
        int prev_mn = get_mn(i);
        if (a[idx].find(i) != a[idx].end())
            p[i].erase(p[i].find(a[idx][i]));
        a[idx][i] += cnt;
        p[i].insert(a[idx][i]);
        int nxt_mn = get_mn(i);
        forn (j, 0, nxt_mn - prev_mn)
            ans = mul(ans, i);
    }
    cerr << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, q;
    cin >> n >> q;
    a.resize(n);
    p.resize(N);
    forn (i, 0, n) {
        int x;
        cin >> x;
        upd(i, x);
    }
    cerr << ans << "\n";
    while (q --> 0) {
        int i, x;
        cin >> i >> x, --i;
        upd(i, x);
        cout << ans << "\n";
    }
    return 0;
}