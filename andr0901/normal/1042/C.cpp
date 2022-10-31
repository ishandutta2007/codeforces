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
    int n;
    cin >> n;
    vector <int> a(n);
    int cnt = 0;
    forn (i, 0, n) {
        cin >> a[i];
        if (!a[i])
            a[i] = 1e9 + 7;
        else if (a[i] < 0)
            cnt++;
    }
    if (cnt % 2) {
        int mx = -1;
        forn (i, 0, n) 
            if (a[i] < 0 && (mx == -1 || a[i] > a[mx]))
                mx = i;
        a[mx] = 1e9 + 7;
    }
    int prev = -1;
    forn (i, 0, n) {
        if (a[i] == 1e9 + 7) {
            prev = i;
            break;
        }
    }
    if (prev != -1) {
        forn (i, prev + 1, n) {
            if (a[i] == 1e9 + 7) {
                cout << "1 " << prev + 1 << " " << i + 1 << "\n";
                prev = i;
            }
        }
        bool ok = 0;
        forn (i, 0, n) 
            if (a[i] != 1e9 + 7)
                ok = 1;
        if (ok)
            cout << "2 " << prev + 1 << "\n";
    }
    prev = -1;
    forn (i, 0, n) {
        if (a[i] != 1e9 + 7) {
            prev = i;
            break;
        }
    }
    forn (i, prev + 1, n) {
        if (a[i] != 1e9 + 7) {
            cout << "1 " << prev + 1 << " " << i + 1 << "\n";
            prev = i;
        }
    }
    return 0;
}