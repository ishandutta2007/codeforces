#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
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
    int n, q;
    cin >> n >> q;
    deque <int> a(n);
    forn (i, 0, n)
        cin >> a[i];
    vector <pii> b(q);
    forn (i, 0, q) {
        cin >> b[i].fs, b[i].fs--;
        b[i].sc = i;
    }
    sort(all(b));
    int mx = *max_element(all(a)), i = 0, j = 0;
    vector <pii> ans(q);
    while (a.front() != mx) {
        while (j < q && b[j].fs <= i) {
            if (b[j].fs == i)
                ans[b[j].sc] = {a[0], a[1]};
            j++;
        }
        int A = a[0], B = a[1];
        a.pop_f(), a.pop_f();
        if (A > B)
            a.pf(A), a.pb(B);
        else 
            a.pf(B), a.pb(A);
        i++;
    }
    forn (k, j, q) 
        ans[b[k].sc] = {mx, a[(b[k].fs - i) % (n - 1) + 1]};
    forn (i, 0, q)
        cout << ans[i].fs << " " << ans[i].sc << "\n";
    return 0;
}