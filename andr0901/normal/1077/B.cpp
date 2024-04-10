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
    vector <int> a(n);
    forn (i, 0, n)
        cin >> a[i];
    int ans = 0;
    forn (i, 1, n - 1) {
        if (a[i - 1] == 1 && a[i] == 0 && a[i + 1] == 1) {
            a[i + 1] = 0;
            ans++;
        }
    }
    cout << ans;
    return 0;
}