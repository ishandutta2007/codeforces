#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define int long long

typedef long long ll;

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, s;
    cin >> n >> s;
    vector <int> a(n);
    forn (i, 0, n)
        cin >> a[i];
    sort(a.begin(), a.end());
    int sum = 0;
    forn (i, 1, n)
        sum += a[i] - a[0];
    if (sum >= s) {
        cout << a[0];
        return 0;
    }
    s -= sum;
    if (a[0] - (s + n - 1) / n < 0)
        cout << -1;
    else
        cout << a[0] - (s + n - 1) / n;
    return 0;
}