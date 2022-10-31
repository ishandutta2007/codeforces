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
template <typename T> ostream& operator<<(ostream& out, const vector <T>& a)  {for (auto& i : a) out << i << " "; return out;}
template <typename T, typename U> void chkmin(T& a, U b) {if (a > b) a = b;}
template <typename T, typename U> void chkmax(T& a, U b) {if (a < b) a = b;}

vector <bool> sieve(int n) {
    vector <bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    forn (i, 2, n + 1) {
        if (is_prime[i] && 1LL * i * i <= n) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    return is_prime;
}

vector<bool> is_prime;

long long solve(const vector<int>& a) {
    int n = a.size();
    vector<int> l(n), r(n);
    forn (i, 0, n) {
        l[i] = (i == 0 ? 0 : l[i - 1]) + 1;
        if (a[i] != 1) {
            l[i] = 0;
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        r[i] = (i == n - 1 ? 0 : r[i + 1]) + 1;
        if (a[i] != 1) {
            r[i] = 0;
        }
    }
    long long ans = 0;
    forn (i, 0, n) {
        if (is_prime[a[i]]) {
            ans += 1LL
                * ((i == 0 ? 0 : l[i - 1]) + 1)
                * ((i == n - 1 ? 0 : r[i + 1]) + 1) - 1;
        }
    }
    cerr << a << "\n" << l << "\n" << r << "\n" << ans << "\n---\n";
    return ans;
}

void solve() {
    int n, e;
    cin >> n >> e;
    vector<int> a(n);
    cin >> a;
    long long ans = 0;
    forn (i, 0, e) {
        vector<int> b;
        for (int j = i; j < n; j += e) {
            b.push_back(a[j]);
        }
        ans += solve(b);
    }
    cout << ans << "\n";
}

constexpr int N = 1e6 + 5;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    is_prime = sieve(N);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}