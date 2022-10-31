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
    Segtree(vector <U> a) : n(sz(a)) {
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

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    vector <vector <int>> letters(26);
    forn (i, 0, sz(s))
        letters[s[i] - 'a'].pb(i);
    forn (i, 0, 26)
        reverse(all(letters[i]));
    Segtree <int> tr(vector <int> (n, 1));
    long long ans = 0;
    for (int i = sz(s) - 1; i >= 0; --i) {
        int j = letters[s[i] - 'a'].back();
        cerr << j << " ";
        letters[s[i] - 'a'].pop_back();
        tr.upd(j, 0);
        ans += tr.get(0, j);
    }
    cout << ans;
    return 0;
}