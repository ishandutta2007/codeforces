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

constexpr int N = 1e6 + 5;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    vector <bool> is_prime = sieve(N);
    vector <int> sq(N);
    forn (i, 0, N)
        if (1LL * i * i < N)
            sq[i * i] = i;
    vector <int> ans(N);
    forn (i, 1, N) {
        ans[i] = ans[i - 1];
        if (is_prime[i])
            ++ans[i];
        if (sq[i] && is_prime[sq[i]])
            --ans[i];
    }
    int q;
    cin >> q;
    while (q --> 0) {
        int n;
        cin >> n;
        cout << ans[n] + 1 << "\n";
    }
    return 0;
}