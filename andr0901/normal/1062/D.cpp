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
    ll ans = 0;
    forn (i, 2, n + 1)
        for (int j = 2 * i; j <= n; j += i)
            ans += (j / i);
    cout << 4 * ans;
    return 0;
}