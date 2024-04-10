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

template <typename T>
class Segtree {
private:
    int n;
    vector <T> tr;
    T neutral_tr = 0;

    T merge(T a, T b) {
        return a + b;
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
        for (i += n, tr[i] = x; i /= 2; i > 0)
            tr[i] = merge(tr[2 * i], tr[2 * i + 1]);
    }
};

void no() {
    cout << "NO";
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    set <int> pluses;
    Segtree <long long> tr(2 * n);
    vector <int> where(n + 1);
    forn (i, 0, 2 * n) {
        char c;
        cin >> c;
        if (c == '-') {
            int x;
            cin >> x;
            tr.upd(i, x);
            where[x] = i;
        } else {
            pluses.insert(i);
        }
    }
    vector <int> ans(2 * n, -1);
    forn (i, 1, n + 1) {
        cerr << i << " ";
        int j = where[i];
        auto k = pluses.lower_bound(j);
        if (k == pluses.begin())
            no();
        --k;
        cerr << *k << " " << j << "\n";;
        cerr << "kek\n";
        if (tr.get(*k, j) != 0)
            no();
        ans[*k] = i;
        pluses.erase(k);
        tr.upd(j, 0);
    }
    cout << "YES\n";
    forn (i, 0, 2 * n)
        if (ans[i] != -1)
            cout << ans[i] << " ";
    return 0;
}