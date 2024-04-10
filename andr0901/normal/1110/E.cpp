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
    int n;
    cin >> n;
    vector <int> a(n), b(n);
    forn (i, 0, n)
        cin >> a[i];
    forn (i, 0, n)
        cin >> b[i];
    if (a[0] != b[0] || a.back() != b.back())
        return cout << "No", 0;
    forn (i, 0, n - 1)
        a[i] = a[i + 1] - a[i];
    a.pop_back();
    forn (i, 0, n - 1)
        b[i] = b[i + 1] - b[i];
    b.pop_back();
    sort(all(a)), sort(all(b));
    forn (i, 0, n - 1)
        if (a[i] != b[i])
            return cout << "No", 0;
    cout << "Yes";
    return 0;
}