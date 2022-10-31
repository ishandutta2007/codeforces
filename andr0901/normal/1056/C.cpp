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

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <int> a(2 * n);
    forn (i, 0, 2 * n) 
        cin >> a[i];
    vector <pii> special(m);
    forn (i, 0, m)
        cin >> special[i].fs >> special[i].sc, special[i].fs--, special[i].sc--;
    vector <bool> used(2 * n);
    int turn;
    cin >> turn;
    if (turn == 1) {
        forn (i, 0, m) {
            if (a[special[i].fs] > a[special[i].sc]) 
                cout << special[i].fs + 1 << endl;
            else 
                cout << special[i].sc + 1 << endl;
            int ans;
            cin >> ans, ans--;
            used[special[i].fs] = used[special[i].sc] = 1;
        }
        forn (i, 0, n - m) {
            int mx = -1, idx;
            forn (j, 0, 2 * n) 
                if (!used[j] && a[j] > mx) 
                    mx = a[j], idx = j;
            cout << idx + 1 << endl;
            int ans;
            cin >> ans, ans--;
            used[ans] = used[idx] = 1;
        }
    } else {
        forn (i, 0, n) {
            int ans;
            cin >> ans, ans--;
            used[ans] = 1;
            bool ok = 1;
            forn (j, 0, m) {
                if (!used[special[j].sc] && special[j].fs == ans) {
                    cout << special[j].sc + 1 << endl;
                    used[special[j].fs] = used[special[j].sc] = 1;
                    ok = 0;
                }
                if (!used[special[j].fs] && special[j].sc == ans) {
                    cout << special[j].fs + 1 << endl;
                    used[special[j].fs] = used[special[j].sc] = 1;
                    ok = 0;
                }
            }
            if (!ok)
                continue;
            int mx = -1, idx;
            ok = 0;
            forn (j, 0, m) {
                if (!used[special[j].fs]) {
                    if (a[special[j].fs] > a[special[j].sc]) {
                        cout << special[j].fs + 1 << endl;
                        used[special[j].fs] = 1;
                    } else {
                        cout << special[j].sc + 1 << endl;
                        used[special[j].sc] = 1;
                    }
                    ok = 1;
                    break;
                }
            }
            if (ok)
                continue;
            forn (j, 0, 2 * n) 
                if (!used[j] && a[j] > mx) 
                    mx = a[j], idx = j;
            cout << idx + 1 << endl;
            used[idx] = 1;
        }
    }
    return 0;
}