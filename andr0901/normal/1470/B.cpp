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

mt19937 rng(time(0));

constexpr int MOD_1 = 1e9 + 7, MOD_2 = 998244353;
int base_1 = (rng() % 1'000'000'000), base_2 = (rng() % 1'000'000'000);

vector<int> p_1, p_2;

pii get(int x) {
    pii ans = {0, 0};
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            int cnt = 0;
            while (x % i == 0) {
                ++cnt;
                x /= i;
            }
            if (cnt % 2) {
                ans.fs = (ans.fs + p_1[i]) % MOD_1;
                ans.sc = (ans.sc + p_2[i]) % MOD_2;
            }
        }
    }
    if (x > 1) {
        ans.fs = (ans.fs + p_1[x]) % MOD_1;
        ans.sc = (ans.sc + p_2[x]) % MOD_2; 
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    map<pii, int> a;
    forn (i, 0, n) {
        int x;
        cin >> x;
        a[get(x)]++;
    }
    int cnt_even = 0, mx_odd = 0;
    int ans_zero = 0;
    for (auto [val, cnt] : a) {
        cerr << cnt << "\n";
        chkmax(ans_zero, cnt);
        if ((val.fs == 0 && val.sc == 0) || cnt % 2 == 0) {
            cnt_even += cnt;
        } else {
            chkmax(mx_odd, cnt);
        }
    }
    int q;
    cin >> q;
    while (q --> 0) {
        long long x;
        cin >> x;
        if (x == 0) {
            cout << ans_zero;
        } else {
            cout << max(cnt_even, mx_odd);
        }
        cout << "\n";
    }
    cerr << "\n";
}

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

constexpr int N = 1e6 + 50;

int main() {
    vector<bool> is_prime = sieve(N);
    int lst_1 = base_1, lst_2 = base_2;
    p_1.resize(N), p_2.resize(N); 
    forn (i, 0, N) {
        if (is_prime[i]) {
            lst_1 = (1LL * lst_1 * base_1) % MOD_1;
            lst_2 = (1LL * lst_2 * base_2) % MOD_2;
            p_1[i] = lst_1;
            p_2[i] = lst_2;
        }
    }
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}