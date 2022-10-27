#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
void abc() {cout << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cout << a << ' ', abc(b...);
}
template <typename T> void printv(T l, T r) {
    for (; l != r; ++l) cout << *l << " \n"[l + 1 == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    bool is = false;
    if (a.empty()) return o << "{}";
    for (T i : a) {o << (is ? ' ' : '{'), is = true, o << i;}
    return o << '}';
}
template <typename T> struct vv : vector <vector <T>> {
    vv (int n, int m, T v) : vector <vector <T>> (n, vector <T>(m, v)) {}
    vv (int n, int m) : vector <vector <T>> (n, vector <T>(m)) {}
    vv () {}
};
template <typename T> struct vvv : vector <vv <T>> {
    vvv (int n, int m, int k, T v) : vector <vv <T>> (n, vv <T>(m, k, v)) {}
    vvv (int n, int m, int k) : vector <vv <T>> (n, vv <T>(m, k)) {}
    vvv () {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 1 << 19, B = 550;

struct Sieve {
    int lp[N], mu[N];
    Sieve () {
        vector <int> p;
        for (int i = 2; i < N; ++i) {
            if (!lp[i]) {
                p.push_back(i);
                lp[i] = i;
            }
            for (int j = 0; 1ll * p[j] * i < N; ++j) {
                lp[p[j] * i] = p[j];
                if (i % p[j] == 0) 
                    break;
            }
        }
        mu[1] = 1;
        for (int i = 2; i < N; ++i) {
            if (lp[i] == lp[i / lp[i]]) 
                mu[i] = 0;
            else 
                mu[i] = mu[i / lp[i]] * -1;
        }
    }
    vector <pair <int, int>> pfactor(int x) {
        vector <pair <int, int>> now;
        while (x > 1) {
            int p = lp[x];
            if (!now.empty() && now.back().first == p)
                now.back().second++;
            else
                now.emplace_back(p, 1);
            x /= p;
        }
        return now;
    }
    vector <int> factor(int x) {
        vector <int> now = {1};
        while (x > 1) {
            int p = lp[x], cnt = 0;
            while (x % p == 0)
                cnt++, x /= p;
            vector <int> nxt;
            for (int i = 0, cur = 1; i <= cnt; ++i) {
                for (int j : now)
                    nxt.push_back(cur * j);
                cur *= p;
            }
            now = nxt;
        }
        sort(all(now));
        return now;
    }
} NT;

ll modpow(ll a, int b) {
    ll ans = 1;
    for (; b; b >>= 1, a = a * a % mod) {
        if (b & 1) ans = ans * a % mod;
    }
    return ans;
}

void solve() {
    int n; ll m;
    cin >> n >> m;
    ll ans = m % mod, cur = m, tans = 0;
    for (int i = 2; i <= n; ++i) {
        if (NT.lp[i] == i) {
            cur /= i;
        }
        ans = ans * (cur % mod) % mod;
        (tans += modpow(m % mod, i) + mod - ans) %= mod;
    }
    cout << tans << '\n';
}

int main() {
    owo;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}