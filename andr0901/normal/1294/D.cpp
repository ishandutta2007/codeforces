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
        for (i += n, tr[i] = x; i /= 2; i > 0)
            tr[i] = merge(tr[2 * i], tr[2 * i + 1]);
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int q, x;
    cin >> q >> x;
    vector <long long> last(x);
    forn (i, 0, x)
        last[i] = i;
    Segtree tr(4e5 + 5);
    forn (i, 0, q) {
        int y;
        cin >> y;
        y %= x;
        if (last[y] < 4e5 + 5)
            tr.upd(last[y], 1);
        last[y] += x;
        int l = 0, r = 4e5 + 5;
        while (r - l > 1) {
            int m = l + r >> 1;
            if (tr.get(0, m) < m)
                r = m;
            else
                l = m;
        }
        //forn (i, 0, q + x)
          //  cout << tr.get(0, i) << " ";
        cout << l;
        cout << "\n";
    }
    return 0;
}