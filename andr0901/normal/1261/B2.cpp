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

class Segtree {
private:
    int n;
    vector <vector <int>> tr;
    int neutral_tr = 0;

    vector <int> merge(vector <int> a, vector <int> b) {
        int i = 0, j = 0;
        vector <int> ans;
        while (i < a.size() && j < b.size()) {
            if (a[i] < b[j])
                ans.pb(a[i++]);
            else
                ans.pb(b[j++]);
        }
        while (i < a.size())
            ans.pb(a[i++]);
        while (j < b.size())
            ans.pb(b[j++]);
        return ans;
    }

    void build(const vector <int>& a) {
        forn (i, 0, n) 
            tr[i + n] = {a[i]};
        for (int i = n - 1; i > 0; i--)
            tr[i] = merge(tr[2 * i], tr[2 * i + 1]);
    }
public:
    Segtree(const vector <int>& a) {
        n = sz(a);
        tr.resize(2 * n);
        build(a);
    }

    int get(int l, int r, int x) {
        int ans = 0;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l % 2) {
                ans += lower_bound(all(tr[l]), x) - tr[l].begin();
                ++l;
            }
            if (r % 2) {
                --r;
                ans += lower_bound(all(tr[r]), x) - tr[r].begin();
            }
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <pii> a(n);
    forn (i, 0, n) {
        cin >> a[i].fs;
        a[i].sc = i;
    }
    sort(all(a), [](pii a, pii b) {
        if (a.fs == b.fs)
            return a.sc < b.sc;
        return a.fs > b.fs;
    });
    vector <int> b(n);
    map <int, int> rev;
    forn (i, 0, n) {
        b[i] = a[i].sc;
        rev[a[i].sc] = a[i].fs;
        //cout << b[i] << " ";
    }
    Segtree tr(b);
    int q;
    cin >> q;
    while (q --> 0) {
        int k, pos;
        cin >> k >> pos, pos--;
        int l = 0, r = n;
        while (r - l > 1) {
            int m = l + r >> 1;
            //cout << m << " " << tr.get(0, k, m) << "\n";
            if (tr.get(0, k, m) <= pos)
                l = m;
            else
                r = m;
        }
        cout << rev[l] << "\n";
    }
    return 0;
}