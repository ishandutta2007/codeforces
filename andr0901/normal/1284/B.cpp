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
        for (i += n, tr[i] += x; i /= 2; i > 0)
            tr[i] = merge(tr[2 * i], tr[2 * i + 1]);
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    Segtree mins(1e6 + 1), maxs(1e6 + 1);
    long long ans = 1LL * n * n;
    forn (i, 0, n) {
        int k;
        cin >> k;
        vector <int> cur(k);
        int mn = 1e9, mx = -1e9;
        forn (j, 0, k) {
            int t;
            cin >> t;
            mn = min(mn, t);
            mx = max(mx, t);
            cur[j] = t;
        }
        bool has = false;
        forn (j, 1, k)
            if (cur[j - 1] < cur[j])
                has = true;
        if (has)
            continue;
        if (mn == mx)
            ans--;
        //cout << i << " ";
        ans -= maxs.get(0, mn + 1);
        //cout << ans << " ";
        ans -= mins.get(mx, 1e6 + 1);
        mins.upd(mn, 1);
        maxs.upd(mx, 1);
        //cout << " " << ans << "\n";
    }
    cout << ans;
    return 0;
}