/*973496160
973701120
973728000
973733888
973838250
973944000
973969920
974053080
974131200
974177280
974219400
974245440
974371860
974413440
974445360
974561280
974584098
974592000
974635200
974668800
974856960
974868480
974877120
974942526
974994720
975051000
975127440
975134160
975151872
975175680
975233280
975240000
975265380
975345840
975374400
975394980
975421440
975453120
975455040
975460500
975492000
975584610
975691008
975744000
975794820*/

#pragma GCC optimize("Ofast")
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

template <typename T> istream& operator>>(istream& in, vector <T>& a) {for (auto& i : a) in >> i; return in;}
template <typename T> ostream& operator<<(ostream& out, vector <T>& a)  {for (auto& i : a) out << i << " "; return out;}
template <typename T, typename U> void chkmin(T& a, U b) {if (a > b) a = b;}
template <typename T, typename U> void chkmax(T& a, U b) {if (a < b) a = b;}

#define int long long

vector <bool> sieve(int n) {
    vector <bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    forn (i, 2, n + 1)
        if (is_prime[i] && 1LL * i * i <= n)
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
    return is_prime;
}

vector <int> primes;

const long long INF = 1e18;

long long ask(long long x) {
    cout << "? " << x << endl;
    long long ans;
    cin >> ans;
    return ans;
}

bool overflow(long long a, long long b) {
    return a >= (INF + b - 1) / b;
}

int get(long long x, vector <int>& powers) {
    for (int i = sz(powers) - 1; i >= 0; --i)
        if (x % powers[i] == 0) {
            return i + 1;
        }
}

void solve() {
    vector <bool> to_check(sz(primes));
    long long product = 1;
    int cnt = 0, i = 0;
    while (i < sz(primes)) {
        while (i < sz(primes) && product < INF / primes.back()) {
            product *= primes[i];
            //cout << primes[i] << " ";
            ++i;
        }
        long long t = ask(product);
        forn (j, 0, sz(primes))
            if (t % primes[j] == 0)
                to_check[j] = true;
        product = 1;
        cnt++;
    }
    vector <int> p;
    forn (i, 0, sz(to_check))
        if (to_check[i])
            p.pb(primes[i]);
    vector <vector <int>> powers(sz(p));
    forn (i, 0, sz(p)) {
        long long cur = 1;
        while (cur < 1e9) {
            powers[i].pb(cur);
            cur *= p[i];
        }
    }
    long long ans = 1;
    for (int i = 0; 2 * i + 1 < sz(p); i++) {
        long long t = ask(1LL * powers[2 * i].back() * powers[2 * i + 1].back());
        ans *= 1LL * get(t, powers[2 * i]);
        ans *= 1LL * get(t, powers[2 * i + 1]);
    }   
    if (sz(p) % 2) {
        long long t = ask(1LL * powers.back().back());
        ans *= 1LL * get(t, powers.back());
    }
    //cerr << p << "\n";
    chkmax(ans, 4);
    cout << "! " << ans * 2 << endl;
}

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    auto is_prime = sieve(6e2 + 50);
    forn (i, 0, sz(is_prime))
        if (is_prime[i])
            primes.pb(i);
    //cout << sz(primes) << "\n" << primes << "\n";
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}