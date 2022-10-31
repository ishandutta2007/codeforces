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

#define v first
#define x second

#define int long long

class Segtree {
private:
    int n;
    vector <int> tr;
    int neutral_tr = 0;

    int merge(int a, int b) {
        return a + b;
    }

    void build(const vector <int>& a) {
        forn (i, 0, n) 
            tr[i + n] = a[i];
        for (int i = n - 1; i > 0; i--)
            tr[i] = merge(tr[2 * i], tr[2 * i + 1]);
    }
public:
    Segtree(const vector <int>& a) {
        n = sz(a);
        tr.resize(2 * n, neutral_tr);
        build(a);
    }

    Segtree(int _n) {
        n = _n;
        tr.resize(2 * n, neutral_tr);
    }

    int get(int l, int r) {
        int ans = neutral_tr;
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

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <int> cords;
    vector <pii> a(n); 
    forn (i, 0, n) {
        cin >> a[i].x;
        cords.pb(a[i].x);
    }
    sort(all(cords)), cords.erase(unique(all(cords)), cords.end());
    map <int, int> get;
    forn (i, 0, sz(cords))
        get[cords[i]] = i;
    forn (i, 0, n)  
        cin >> a[i].v;
    sort(all(a));
    Segtree pref(n), cnt(n);
    long long ans = 0;
    forn (i, 0, n) {
        ans -= pref.get(0, get[a[i].x]) - a[i].x * cnt.get(0, get[a[i].x]);
        pref.upd(get[a[i].x], a[i].x), cnt.upd(get[a[i].x], 1);
    }
    cout << ans;
    return 0;
}