#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n + 1);
    forn (i, 1, n + 1)
        cin >> a[i];
    int ans = 0;
    forn (i, 1, n + 1)
        ans += a[i] * 4 * (i - 1);
    cout << ans;
    return 0;
}