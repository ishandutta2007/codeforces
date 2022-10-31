//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

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

const int INF = 2e9;
int n;
pii neutral_tr = {INF, 0};

pii merge(pii a, pii b) {
    pii ans;
    if (a.fs > b.fs)
        ans.sc = b.sc;
    else 
        ans.sc = a.sc;
    ans.fs = min(a.fs, b.fs);
    return ans;
}

pii get(const vector <pii>& tr, int l, int r) {
    pii ans = neutral_tr;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
        if (l % 2)
            ans = merge(ans, tr[l++]);
        if (r % 2)
            ans = merge(ans, tr[--r]);
    }
    return ans;
}
void upd(vector <pii>& tr, int i, int x) {
    for (i += n, tr[i].fs = x; i /= 2; i > 1)
        tr[i] = merge(tr[2 * i], tr[2 * i + 1]);
}

void insert(vector <vector <pii>>& a, int idx, int x) {
    int _x = x;
    forn (i, 0, 10) {
        if (_x % 10)
            upd(a[i], idx, x);
        _x /= 10;
    }
}

void erase(vector <vector <pii>>& a, int idx, int x) {
    forn (i, 0, 10) {
        if (x % 10) 
            upd(a[i], idx, INF);
        x /= 10;
    }
}

int get_min(vector <pii>& a, int l, int r) {
    pii t = get(a, l, r);
    if (t.fs == INF)
        return INF;
    upd(a, t.sc, INF);
    pii u = get(a, l, r);
    upd(a, t.sc, t.fs);
    if (u.fs == INF) 
        return INF;
    return t.fs + u.fs;
}

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    /*forn (i, 0, 10)
        forn (j, i, 10) 
            if ((i + j) % 10 == i || (i + j) % 10 == j)
                cout << i << " " << j << "\n";*/
    int m;
    cin >> n >> m;
    vector <vector <pii>> a(10, vector <pii> (2 * n, neutral_tr));
    forn (i, 0, 10)
        forn (j, n, 2 * n)
            a[i][j] = {INF, j - n};
    vector <int> b(n);
    forn (i, 0, n) {    
        cin >> b[i];
        insert(a, i, b[i]);
    }   
    while (m --> 0) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int i, x;
            cin >> i >> x, i--;
            erase(a, i, b[i]);
            b[i] = x;
            insert(a, i, b[i]);
        } else {
            int l, r;
            cin >> l >> r, l--;
            int ans = INF;
            forn (i, 0, 10) 
                ans = min(ans, get_min(a[i], l, r));
            if (ans == INF) 
                cout << "-1\n";
            else 
                cout << ans << "\n";
        }
        /*forn (i, 0, 6) {
            forn (j, 0, n) 
                cout << get(a[i], j, j + 1).fs << " ";
            cout << "\n";
        }
        cout << "\n\n";*/
    }
    return 0;
}