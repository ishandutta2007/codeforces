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
#define int long long

void floyd(vector <vector <int>>& gr) {
    forn (k, 0, 10) 
        forn (i, 0, 10) 
            forn (j, 0, 10) 
                gr[i][j] = min(gr[i][j], gr[i][k] + gr[k][j]);
}

int dst(int a, int b, vector <vector <int>>& gr) {
    return gr[a][b];
}

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    string s;
    cin >> s;
    forn (i, 0, sz(s))
        s[i] -= '0';
    forn (i, 0, 10) {
        forn (j, 0, 10) {
            vector <vector <int>> gr(10, vector <int> (10, 1e9));
            forn (k, 0, 10) {
                gr[k][(k + i) % 10] = 1;
                gr[k][(k + j) % 10] = 1;
            }
            floyd(gr);
            ll ans = 0;
            forn (k, 1, sz(s)) {
                if (dst(s[k - 1], s[k], gr) >= 1e9) {
                    ans = -1;
                    break;
                }
                else 
                    ans += dst(s[k - 1], s[k], gr) - 1;
            }
            cout << ans << " ";
        }
        cout << "\n";
    }
    return 0;
}