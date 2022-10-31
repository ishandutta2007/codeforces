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

#define int long long

constexpr int N = 1e6 + 5;

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    long long needed;
    cin >> n >> m >> needed;
    vector<int> a(n), b(m);
    cin >> a >> b;
    if (n > m) {
        swap(a, b);
        swap(n, m);
    }
    vector<vector<int>> pairs(N);
    forn (i, 0, n)
        pairs[a[i]].pb(i);
    forn (i, 0, m)
        pairs[b[i]].pb(i);
    vector<int> cnt_diff(m);
    forn (i, 0, N)
        if (pairs[i].size() == 2)
            cnt_diff[(pairs[i][1] - pairs[i][0] + m) % m]++;
    int g = __gcd(n, m);
    long long collisions = 0;
    forn (k, 0, m / g) {
        collisions += n - cnt_diff[(1LL * k * n) % m];
        if (collisions >= needed) {
            cerr << "kek: ";
            cerr << k << " ";
            collisions -= n - cnt_diff[(1LL * k * n) % m];
            cerr << collisions << " ";
            forn (i, 0, n) {
                if (b[(i + 1LL * k * n) % m] != a[i]) {
                    ++collisions;
                    if (collisions == needed) {
                        cout << 1LL * k * n + i + 1 << "\n";
                        return 0;
                    }
                }
            }
        }
    }
    long long per_cycle = collisions;
    long long cycles = needed / per_cycle;
    cerr << per_cycle << " " << cycles << "\n";
    needed %= per_cycle;
    if (needed == 0) {
        needed = per_cycle;
        cycles--;
    }
    collisions = 0;
    forn (k, 0, m / g) {
        collisions += n - cnt_diff[(1LL * k * n) % m];
        if (collisions >= needed) {
            collisions -= n - cnt_diff[(1LL * k * n) % m];
            forn (i, 0, n) {
                if (b[(i + 1LL * k * n) % m] != a[i]) {
                    ++collisions;
                    if (collisions == needed) {
                        cout << 1LL * cycles * (1LL * n * m / __gcd(n, m)) + 1LL * k * n + i + 1 << "\n";
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}