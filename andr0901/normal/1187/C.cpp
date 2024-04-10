#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
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

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <bool> covered(n);
    vector <pii> q;
    forn (i, 0, m) {
        int t, l, r;
        cin >> t >> l >> r, l--;
        if (t)
            forn (j, l + 1, r)
                covered[j] = 1;
        else 
            q.eb(l, r);
    }
    vector <int> a(n);
    a[0] = 10000;
    forn (i, 1, n) {
        if (covered[i]) {
            a[i] = a[i - 1] + 1;
        } else {
            a[i] = a[i - 1] - 1;
        }
        //cout << a[i] << " ";
    }
    forn (i, 0, sz(q)) {
        bool ok = 0;
        forn (j, q[i].fs, q[i].sc - 1)  
            if (a[j] > a[j + 1])
                ok = 1;
        if (!ok)
            return cout << "NO", 0;
    }
    cout << "YES\n";
    forn (i, 0, n) 
        cout << a[i] << " ";
    return 0;
}