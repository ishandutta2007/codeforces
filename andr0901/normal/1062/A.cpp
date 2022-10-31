#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define ll long long

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n + 2);
    forn (i, 1, n + 1)
        cin >> a[i];
    a[0] = 0;
    a[n + 1] = 1001;
    int ans = INT_MIN;
    int t = 1;
    forn (i, 0, n + 2) {
        if (i == n + 1 || a[i] != a[i + 1] - 1) {
            ans = max(ans, t);
            t = 1;
        } else  {
            t++;
        }
    }
    if (ans - 2 < 0)
        cout << 0;
    else
        cout << ans - 2;
    return 0;
}