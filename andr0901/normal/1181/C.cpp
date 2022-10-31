#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

struct Segtree {
private:
    int n;
    vector <int> tr;
    int neutral_tr = INT_MAX;

    int merge(int a, int b) {
        return min(a, b);
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
        for (i += n, tr[i] += x; i /= 2; i > 1)
            tr[i] = merge(tr[2 * i], tr[2 * i + 1]);
    }
};

vector <vector <int>> d, r;

int n, m;

int main() {
    //ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    vector <vector <char>> a(n, vector <char> (m));
    forn (i, 0, n) 
        forn (j, 0, m)  
            cin >> a[i][j];
    d.resize(n, vector <int> (m)), r.resize(m, vector <int> (n));
    forn (i, 0, n) {
        forn (j, 0, m) {
            int k = j + 1;
            while (k < m && a[i][k] == a[i][k - 1])
                k++;
            //cout << k << " ";
            forn (l, j, k)
                r[l][i] = k - l;
            j = k - 1;
        }
    }
    forn (i, 0, m) {
        forn (j, 0, n) {
            int k = j + 1;
            while (k < n && a[k][i] == a[k - 1][i])
                k++;
            forn (l, j, k)
                d[l][i] = k - l;
            j = k - 1;
        }
    }
    /*forn (i, 0, n) {
        forn (j, 0, m) 
            cout << r[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
    forn (i, 0, n) {
        forn (j, 0, m) 
            cout << d[i][j] << " ";
        cout << "\n";
    }*/
    vector <Segtree> b;
    forn (i, 0, m)
        b.pb(Segtree(r[i]));
    ll ans = 0;
    forn (i, 0, n) {
        forn (j, 0, m) {
            int len = d[i][j];
            if (i + 3 * len > n)
                continue;
            if (d[i + len][j] != len)
                continue;
            if (d[i + 2 * len][j] < len)
                continue;
            if (a[i][j] == a[i + len][j] || a[i + len][j] == a[i + 2 * len][j])
                continue;
            ans += b[j].get(i, i + 3 * len);
            //cout << i << " " << j << "  " << len << ": " << b[j].get(i, i + 3 * len + 1) << "\n";
        }
    }
    cout << ans;
    return 0;
}