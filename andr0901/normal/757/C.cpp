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

constexpr ull MOD = 1e9 + 7;
constexpr ull MOD2 = 998244353;

ull get_hash_pair(pii a) {
    return a.fs + MOD * a.sc;
}

ull get_hash(vector<pii>& a) {
    vector<int> b;
    for (auto i : a)
        b.pb(get_hash_pair(i));
    ull p = 1;
    for (auto i : b)
        p = (p * MOD2 + i);
    return p;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> occurences(m);
    forn (i, 0, n) {
        map<int, int> cnt;
        int k;
        cin >> k;
        forn (j, 0, k) {
            int x;
            cin >> x;
            cnt[x - 1]++;
        }
        for (auto [val, c] : cnt)
            occurences[val].eb(c, i);
    }
    map<ull, int> cnt;
    forn (i, 0, m)
        cnt[get_hash(occurences[i])]++;
    vector<int> f(1e6 + 10);
    f[0] = 1;
    forn (i, 1, sz(f))
        f[i] = (1LL * f[i - 1] * i) % MOD;
    int ans = 1;
    for (auto [h, c] : cnt)
        ans = (1LL * ans * f[c]) % MOD;
    cout << ans << "\n";
    return 0;
}