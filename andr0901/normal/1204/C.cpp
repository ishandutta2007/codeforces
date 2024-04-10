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

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <vector <int>> gr(n, vector <int> (n, INF));
    forn (i, 0, n) {
        forn (j, 0, n) {
            char c;
            cin >> c;
            if (c == '1')
                gr[i][j] = 1;
            if (c == '0')
                gr[i][j] = INF;
        }
    }
    forn (k, 0, n) 
        forn (i, 0, n)
            forn (j, 0, n) 
                gr[i][j] = min(gr[i][j], gr[i][k] + gr[k][j]);
    int m;
    cin >> m;
    vector <int> a(m);
    forn (i, 0, m)
        cin >> a[i], a[i]--;
    vector <int> ans = {a[0]};
    int last = 0;
    forn (i, 1, m - 1) {
        //cout << a[last] << " " << a[i] << " " << a[i + 1] << '\n';
        if (a[last] == a[i + 1] || gr[a[last]][a[i + 1]] < gr[a[last]][a[i]] + gr[a[i]][a[i + 1]]) {
            ans.pb(a[i]);
            last = i;
        }
    }
    ans.pb(a[m - 1]);
    cout << sz(ans) << "\n";
    for (int i : ans)
        cout << i + 1 << " ";
    return 0;
}