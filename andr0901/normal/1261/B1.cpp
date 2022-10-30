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
    int n;
    cin >> n;
    vector <pii> a(n);
    forn (i, 0, n) {
        cin >> a[i].fs;
        a[i].sc = i;
    }
    sort(all(a), [](pii a, pii b) {
        if (a.fs == b.fs)
            return a.sc < b.sc;
        return a.fs > b.fs;
    });
    int q;
    cin >> q;
    while (q --> 0) {
        int k, pos;
        cin >> k >> pos, pos--;
        vector <pii> b(k);
        forn (i, 0, k)
            b[i] = a[i];
        sort(all(b), [](pii a, pii b) {
            return a.sc < b.sc;
        });
        cout << b[pos].fs << "\n";
    }
    return 0;
}