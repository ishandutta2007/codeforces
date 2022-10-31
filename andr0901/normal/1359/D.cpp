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

template <typename T>
class Segtree {
private:
    int n;
    vector <T> tr;
    T neutral_tr = {1e9, -1e9};

    T merge(T a, T b) {
        return {min(a.fs, b.fs), max(a.sc, b.sc)};
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
        for (i += n, tr[i] = {x, x}; i /= 2; i > 0)
            tr[i] = merge(tr[2 * i], tr[2 * i + 1]);
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    cin >> a;
    vector <vector <int>> idxs(61);
    forn (i, 0, n)
        idxs[a[i] + 30].pb(i);
    Segtree <pii> tr(n);
    int s = 0;
    forn (i, 0, n) {
        s += a[i];
        tr.upd(i, s);
    }
   /* forn (i, 0, n)
        cout << tr.get(i, i + 1).fs << " ";
    cout << "\n";*/
    int ans = 0;
    forn (i, 0, n) {
        int l = -1, r = n;
        forn (j, a[i] + 30 + 1, 61)
            if (lower_bound(all(idxs[j]), i) != idxs[j].end())
                chkmin(r, *lower_bound(all(idxs[j]), i));
        forn (j, a[i] + 30 + 1, sz(idxs))
            if (lower_bound(all(idxs[j]), i) != idxs[j].begin())
                chkmax(l, *(--lower_bound(all(idxs[j]), i)));
        int right_sum = tr.get(i, r).sc;
        int left_sum = tr.get(l + 1, i).fs;
        if (r == i + 1)
            right_sum = tr.get(i, i + 1).sc;
        if (l == i - 1)
            left_sum = tr.get(i, i + 1).sc;
        if (l == i - 1 && r == i + 1 || left_sum == right_sum) {
            continue;
        }
        if (l == -1)
           chkmin(left_sum, 0);
        //cout << i << " " << l << " " << r << " " << right_sum << " " << left_sum <<" " <<  a[i] << "\n";;
        chkmax(ans, right_sum - left_sum - a[i]);
    }
    cout << ans;
    return 0;
}