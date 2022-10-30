#pragma GCC optimize("Ofast")
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

int get(char c) {
    if (c == 'S')
        return 0;
    if (c == 'M')
        return 1;
    if (c == 'L')
        return 2;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <vector <int>> a(4, vector <int> (3));
    auto b = a;
    forn (i, 0, n) {
        string s;
        cin >> s;
        a[s.size() - 1][get(s.back())]++;
    }
    forn (i, 0, n) {
        string s;
        cin >> s;
        //cout << s.size() -1  << " " << get(s.back()) << "\n";
        b[s.size() - 1][get(s.back())]++;
    }
    int ans = 0;
    forn (i, 0, 4)
        forn (j, 0, 3) {
            //cout << a[i][j] << " " << b[i][j] << "\n";
            ans += b[i][j] - min(a[i][j], b[i][j]);
        }
    cout << ans;
    return 0;
}