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

const int MOD = 998244353;

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

template <typename T>
class Segtree {
private:
    int n;
    vector <T> tr;
    T neutral_tr = 1e9;

    T merge(T a, T b) {
        return min(a, b);
    }

    template <typename U>
    void build(const vector <U>& a) {
        forn (i, 0, n) 
            tr[i + n] = a[i];
        for (int i = n - 1; i > 0; i--)
            tr[i] = merge(tr[2 * i], tr[2 * i + 1]);
    }
public:
    template <typename U>
    Segtree(const vector <U>& a) : n(sz(a)) {
        tr.resize(2 * n, neutral_tr);
        build(a);
    }

    Segtree(int _n) : n(_n) {
        tr.resize(2 * n, neutral_tr);
    }

    T get(int l, int r) {
        T ans = neutral_tr;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l % 2)
                ans = merge(ans, tr[l++]);
            if (r % 2)
                ans = merge(ans, tr[--r]);
        }
        return ans;
    }
    
    void upd(int i, int x) {
        for (i += n, tr[i] += x; i /= 2; i > 0)
            tr[i] = merge(tr[2 * i], tr[2 * i + 1]);
    }
};


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <int> a(n), b(m);
    cin >> a >> b;
    map <int, int> lst;
    map <int, vector <int>> idxs;
    forn (i, 0, n) {
        lst[a[i]] = i;
        idxs[a[i]].pb(i);
    }
    vector <int> left_mins(n, -1);
    vector <int> st = {-1};
    for (int i = n - 1; i >= 0; --i) {
        while (st.back() != -1 &&
               a[st.back()] > a[i]) {
            left_mins[st.back()] = i;
            st.pop_back();
        }
        st.pb(i);
    }
    cerr << left_mins << "\n";
    Segtree <int> tr(a);
    if (*min_element(all(a)) != b[0])
        return cout << 0, 0;
    int ans = 1, j = lst[b[0]];
    forn (i, 1, m) {
        auto k = lower_bound(all(idxs[b[i]]), j);
        if (k == idxs[b[i]].end())
            return cout << 0, 0;
        cerr << j << " " << lst[b[i]] << " " << *k << " " << left_mins[*k] << "\n";
        if (i && tr.get(lst[b[i - 1]], left_mins[*k] + 1) != b[i - 1])
            return cout << 0, 0;
        ans = mul(ans, lst[b[i]] - left_mins[*k]);
        j = lst[b[i]];
    }
    int mn = 1e9;
    forn (j, lst[b[m - 1]], n)
        chkmin(mn, a[j]);
    if (mn != b[m - 1])
        return cout << 0, 0;
    cerr << j << "\n";
    cout << ans;
    return 0;
}