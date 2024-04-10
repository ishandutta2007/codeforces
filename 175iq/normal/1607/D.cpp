#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

int main() {
    int t;
    cin >> t;
    forn(tt, t) {
        int n;
        cin >> n;
        vector<int> a(n);
        forn(i, n)
            cin >> a[i];

        string c;
        cin >> c;

        vector<int> l, r;
        forn(i, n)
            (c[i] == 'B' ? l : r).push_back(a[i]);
        sort(l.begin(), l.end());
        sort(r.begin(), r.end(), greater<int>());

        bool ok = true;
        forn(i, l.size())
            if (l[i] < i + 1)
                ok = false;
        forn(i, r.size())
            if (r[i] > n - i)
                ok = false;

        cout << (ok ? "YES" : "NO") << '\n';
    }
}