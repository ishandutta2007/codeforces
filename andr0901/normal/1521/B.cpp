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

set<int> primes;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    int mn = min_element(all(a)) - a.begin();
    if (a[mn] > n) {
        int lst = a[mn] + 1;
        cout << n - 1 << "\n";
        for (int i = mn + 1; i < n; ++i)
            cout << i + 1 << " " << mn + 1 << " " << lst++ << " " << a[mn] << "\n";
        lst = a[mn] + 1;
        for (int i = mn - 1; i >= 0; --i)
            cout << i + 1 << " " << mn + 1 << " " << lst++ << " " << a[mn] << "\n";
    } else {
        vector<int> used;
        cout << n - 1 << "\n";
        forn (i, 0, n)
            if (i != mn) {
                int t = *primes.upper_bound(a[mn]);
                primes.erase(t);
                used.push_back(t);
                cout << i + 1 << " " << mn + 1 << " " << t << " " << a[mn] << "\n";
            }
        for (int t : used)
            primes.insert(t);
    }
}

constexpr int N = 1e7;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    vector<bool> is_prime = sieve(N);
    forn (i, 0, N)
        if (is_prime[i])
            primes.insert(i);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}