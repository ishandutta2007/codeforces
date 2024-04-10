#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define all(x) (x).begin(), (x).end()

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int q;
    cin >> q;
    while (q --> 0) {
        int n;
        cin >> n;
        vector <char> a(n);
        forn (i, 0, n)
            cin >> a[i];
        if (n == 2) {
            if (a[0] >= a[1])
                cout << "NO\n";
            else
                cout << "YES\n2\n" << a[0] << " " << a[1] << "\n";
            continue;
        }
        cout << "YES\n2\n";
        cout << a[0] << " ";
        forn (i, 1, n)
            cout << a[i];
        cout << "\n";
    }
    return 0;
}