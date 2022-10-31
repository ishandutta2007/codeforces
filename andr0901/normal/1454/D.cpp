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

vector <pair <int, long long>> get_divisors(long long n) {
    vector <pair <int, long long>> divisors;
    for (long long i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            divisors.eb(0, i);
            while (n % i == 0) {
                divisors.back().fs++;
                n /= i;
            }
        }
    }
    if (n > 1)
        divisors.eb(1, n);
    return divisors;
}

void solve() {
    long long n;
    cin >> n;
    vector <pair <int, long long>> divisors = get_divisors(n);
    sort(rall(divisors));
    vector <long long> ans;
    forn (i, 1, divisors[0].fs) {
        ans.pb(divisors[0].sc);
        n /= divisors[0].sc;
    }
    ans.pb(n);
    cout << ans.size() << "\n" << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}