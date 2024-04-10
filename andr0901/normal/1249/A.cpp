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

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int q;
    cin >> q;
    while (q --> 0) {
        int n;
        cin >> n;
        vector <int> a(n);
        forn (i, 0, n)
            cin >> a[i];
        bool ok = true;
        sort(all(a));
        forn (i, 1, n)
            if (a[i] - a[i - 1] == 1)
                ok = false;
        if (ok)
            cout << 1;
        else
            cout << 2;
        cout << "\n";
    }
    return 0;
}