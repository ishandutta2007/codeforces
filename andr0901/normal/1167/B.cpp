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
    vector <int> a(4);
    forn (i, 0, 4) {
        cout << "? " << i + 1 << " " << i + 2 << endl;
        cin >> a[i];
    }
    vector <int> p = {4, 8, 15, 16, 23, 42};
    do {
        bool ok = 1;
        forn (i, 1, 5)
            if (p[i - 1] * p[i] != a[i - 1])
                ok = 0;
        if (ok) {
            cout << "! ";
            forn (i, 0, 6)
                cout << p[i] << " ";
            cout << endl;
            return 0;
        }
    } while (next_permutation(all(p)));
    return 0;
}