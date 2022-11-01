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
    int n, k;
    cin >> n >> k;
    vector <int> a(200);
    forn (i, 0, n) {
        int t;
        cin >> t;
        a[t]++;
    }
    int m = -1;
    int cnt = 0;
    forn (i, 0, 200) {
        m = max(1.0 * m, ceil(1.0 * a[i] / k));
        if (a[i] != 0)
            cnt++;
    }
    cout << m * cnt * k - n;
    return 0;
}