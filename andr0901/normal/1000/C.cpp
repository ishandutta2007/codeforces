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
    int n;
    cin >> n;
    vector <pair <long long, int>> a(2 * n);
    forn (i, 0, n) {
        long long l, r;
        cin >> l >> r;
        r++;
        a[2 * i] = {l, 1};
        a[2 * i + 1] = {r, -1};
    }
    sort(all(a));
    vector <long long> ans(n + 1);
    long long bal = 0;
    forn (i, 0, 2 * n - 1) {
        bal += a[i].sc;
        if (a[i].fs != a[i + 1].fs)
            ans[bal] += a[i + 1].fs - a[i].fs;
        //acout << bal << " ";
    }
    forn (i, 1, n + 1)
        cout << ans[i] << " ";
    return 0;
}