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

#ifdef DEBUG
#else
    #define cerr if (false) cerr
#endif

template <typename T> istream& operator>>(istream& in, vector <T>& a) {for (auto& i : a) in >> i; return in;}
template <typename T> ostream& operator<<(ostream& out, vector <T>& a)  {for (auto& i : a) out << i << " "; return out;}
template <typename T, typename U> void chkmin(T& a, U b) {if (a > b) a = b;}
template <typename T, typename U> void chkmax(T& a, U b) {if (a < b) a = b;}

int n, m, k;

vector <vector <pii>> gr;

vector <vector <vector <int>>> d;
vector <vector <int>> h;

vector <int> tr;

int ans = 0, full = 0;


const int MOD = 1e9 + 7;

int add(int x, int y) {
    x += y;
    if (x >= MOD)
        return x - MOD;
    return x;
}

int sub(int x, int y) {
    x -= y;
    if (x < 0)
        return x + MOD;
    return x;
}

int mul(int x, int y) {
    return (1LL * x * y) % MOD;
}

int bin_pow(int a, int p) {
    if (!p)
        return 1;
    if (p % 2)
        return (1LL * bin_pow(a, p - 1) * a) % MOD;
    int t = bin_pow(a, p / 2);
    return (1LL * t * t) % MOD;
}

int inv(int x) {
    return bin_pow(x, MOD - 2);
}


void go(int idx, int hash_sum) {
    // cerr << idx << " ";
    if (idx == k) {
        if (hash_sum == full)
            ++ans;
        return;
    }
    forn (i, 0, idx + 1) {
        go(idx + 1, add(hash_sum, h[idx][i]));
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> k;
    gr.resize(n);
    forn (i, 0, m) {
        int v, u, w;
        cin >> v >> u >> w, --v, --u;
        gr[v].eb(u, w);
    }
    vector <int> p(n);
    p[0] = 1;
    forn (i, 1, n)
        p[i] = mul(p[i - 1], 200003);
    forn (i, 0, n)
        full = add(full, p[i]);
    d = vector <vector <vector <int>>>(k, vector <vector <int>> (k));
    h = vector <vector <int>> (k, vector <int> (k));
    forn (i, 0, n) {
        sort(all(gr[i]), [](pii a, pii b){return a.sc < b.sc;});
        int k = 0;
        for (auto j : gr[i]) {
            h[sz(gr[i]) - 1][k] = add(h[sz(gr[i]) - 1][k],
                                        p[j.fs]);
            ++k;
        }
    }
    tr.resize(n, 0);
    go(0, 0);
    cout << ans;
    return 0;
}