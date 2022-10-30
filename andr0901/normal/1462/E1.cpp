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

vector<long long> f, rev_f;

long long c(int n, int k) {
    if (n < 0 || k < 0 || n - k < 0)
        return 0;
    return 1LL * n * (n - 1) / 2;
    // return f[n] / f[k] / f[n - k];
}

void solve() {
    int n, m, k;
    cin >> n;
    k = 2, m = 3;
    vector<int> a(n);
    cin >> a;
    sort(all(a));
    int j = 0;
    long long ans = 0;
    map<int, int> cnt;
    forn (i, 0, n)
        cnt[a[i]]++;
    forn (i, 0, n) {
        if (i > 0 && a[i] == a[i - 1])
            continue;
        while (j < n && a[j] - a[i] <= k)
            ++j;
        int lim = cnt[a[i]];
        forn (k, 1, lim + 1) {
            ans += c(j - i - k, m - 1);
        }
    }    
    cerr << "\n";
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    f.resize(3e5 + 10);
    rev_f.resize(sz(f));
    f[0] = rev_f[0] = 1;
    forn (i, 1, sz(f)) {
        f[i] = f[i - 1] * i;
    }
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}