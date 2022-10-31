#pragma GCC optimize("Ofast")
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
#define int long long

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <pii> a(n);
    forn (i, 0, n)  
        cin >> a[i].fs, a[i].sc = i;
    sort(all(a));
    vector <int> diff(n + 1);
    multiset <int> b;
    forn (i, 1, n)
        diff[i] = a[i].fs - a[i - 1].fs, b.insert(diff[i]);
    {
        bool ok = 1;
        forn (i, 2, n)
            if (diff[i] != diff[2])
                ok = 0;
        if (ok)
            return cout << a[0].sc + 1, 0;
    } {
        bool ok = 1;
        forn (i, 1, n - 1)
            if (diff[i] != diff[1])
                ok = 0;
        if (ok)
            return cout << a[n - 1].sc + 1, 0;
    }
    forn (i, 2, n) {
       // cout << i << ": ";
        int s = diff[i] + diff[i - 1];
        //cout << s << " " << sz(b) << "\n";
        if (i != n)
            b.erase(b.find(diff[i]));
        if (i != 1)
            b.erase(b.find(diff[i - 1]));
        b.insert(s);
        //cout << s << " ";
        if (*(--b.end()) == *b.begin())
            return cout << a[i - 1].sc + 1, 0;
        if (i != n)
            b.insert(diff[i]);
        if (i != 1)
            b.insert(diff[i - 1]);
        b.erase(b.find(s));
    }
    cout << -1;
    return 0;
}