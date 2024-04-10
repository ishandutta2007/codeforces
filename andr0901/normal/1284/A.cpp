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

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <string> a(n), b(m);
    forn (i, 0, n)
        cin >> a[i];
    forn (i, 0, m)
        cin >> b[i];
    int t;
    cin >> t;
    while (t --> 0) {
        int x;
        cin >> x, x--;
        x %= n * m;
        cout << a[x % n] << b[x % m] << "\n";
    }
    return 0;
}