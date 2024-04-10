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

constexpr int N = 1e7 + 5;
constexpr ull MOD = 1e9 + 9;
vector<ull> get_h;

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

// from emaxx
int lp[N+1];
vector<int> pr;
 
void find_lp() {
for (int i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back (i);
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}

ull factorize(int n) {
    ull h = 0;
    while (n > 1) {
        int p = lp[n];
        int cnt = 0;
        while (n % p == 0) {
            n /= p;
            ++cnt;
        }
        if (cnt % 2)
            h += get_h[p];
    }
    return h;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    cin >> a;
    map<ull, int> lst;
    vector<int> left(n);
    forn (i, 0, n) {
        ull h = factorize(a[i]);
        if (lst.find(h) == lst.end())
            left[i] = -1;
        else
            left[i] = lst[h];
        lst[h] = i;
    }
    cerr << left << "\n";
    int ans = 0;
    int j = n;
    for (int i = n - 1; i >= 0; --i) {
        if (i <= j) {
            j = -1;
            ++ans;
        }
        chkmax(j, left[i]);
        cerr << i << " " << j << "\n";
    }
    cerr << "\n";
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    vector<bool> is_prime = sieve(N);
    get_h.resize(N);
    ull lst = MOD;
    forn (i, 0, N)
        if (is_prime[i]) {
            get_h[i] = lst;
            lst *= MOD;
        }
    find_lp();
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}