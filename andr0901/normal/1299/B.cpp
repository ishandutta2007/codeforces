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
#define int long long

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <pii> a(n);
    forn (i, 0, n) {
        cin >> a[i].fs >> a[i].sc;
        a[i].fs *= 2, a[i].sc *= 2;
    }
    if (n % 2)
        return cout << "NO", 0;
    pii center = {(a[0].fs + a[n / 2].fs) / 2, 
                  (a[0].sc + a[n / 2].sc) / 2};
    forn (i, 0, n) {
        a[i].fs -= center.fs;
        a[i].sc -= center.sc;
    }
    //cout << center.fs << " " << center.sc << "\n";
    forn (i, 0, n / 2) 
        if (-a[i].fs != a[i + n / 2].fs || -a[i].sc != a[i + n / 2].sc)
            return cout << "NO", 0;
    cout << "YES\n";
    return 0;
}