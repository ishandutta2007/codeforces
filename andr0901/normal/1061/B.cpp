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
    int n, m;
    cin >> n >> m;
    vector <int> a(n + 1);
    ll sum = 0;
    forn (i, 0, n) {
        cin >> a[i];
        sum += a[i];
    }
    a[n] = 0;
    sort(a.begin(), a.end());
    ll ans = 0;
    int j = 0;
    forn (i, 1, n + 1) {
        if (a[i] > j)
            j++;
        ans++;
    }
    if (j < a[n])
        ans += a[n] - j;
    cout << sum - ans;
    return 0;
}