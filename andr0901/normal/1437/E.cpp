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

constexpr int INF = 1e9;

template <typename T>
class Segtree {
private:
    const int n;
    vector <T> tr;
    const function <T(T, T)> merge;
    const T neutral_tr;

    template <typename U>
    void build(const vector <U>& a) {
        forn (i, 0, n)
            tr[i + n] = a[i];
        for (int i = n - 1; i > 0; i--)
            tr[i] = merge(tr[2 * i], tr[2 * i + 1]);
    }
public:
    template <typename U>
    Segtree(const vector <U>& a, function <T(T, T)> _merge, T _neutral_tr) : n(sz(a)), merge(_merge), neutral_tr(_neutral_tr) {
        tr.resize(2 * n, neutral_tr);
        build(a);
    }

    Segtree(int _n, function <T(T, T)> _merge, T _neutral_tr) : n(_n), merge(_merge), neutral_tr(_neutral_tr) {
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
        for (i += n, tr[i] = max(tr[i], x); i /= 2; i > 0)
            tr[i] = merge(tr[2 * i], tr[2 * i + 1]);
    }
};

int solve(vector <int> a) {
    cerr << a << "\n";
    vector <int> tmp = a;
    sort(all(tmp)), tmp.erase(unique(all(tmp)), tmp.end());
    map <int, int> get;
    forn (i, 0, sz(tmp))
        get[tmp[i]] = i;
    forn (i, 0, sz(a))
        a[i] = get[a[i]];
    Segtree <int> tr(sz(a), 
                     [](const auto& a, const auto& b){return max(a, b);}, 
                     -INF);
    tr.upd(a[0], 1);
    forn (i, 1, sz(a)) {
        tr.upd(a[i], tr.get(0, a[i] + 1) + 1);
    }
    int len = tr.get(a.back(), a.back() + 1) - 2;
    cerr << a << "\n";
    if (len < 0) {
        cout << -1;
        exit(0);
    }
    return sz(a) - 2 - len;

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector <int> a(n + 2);
    a[0] = -INF;
    forn (i, 1, n + 1)
        cin >> a[i];
    a[n + 1] = 2 * INF;
    forn (i, 0, n + 2)
        a[i] -= i;
    cerr << a << "\n\n";
    vector <int> b(k + 2);
    forn (i, 1, k + 1)
        cin >> b[i];
    b[k + 1] = n + 1;
    int ans = 0;
    forn (i, 1, k + 2) {
        int l = b[i - 1], r = b[i];
        ans += solve(vector <int> (a.begin() + l, a.begin() + r + 1));
    }
    cout << ans;    
    return 0;
}