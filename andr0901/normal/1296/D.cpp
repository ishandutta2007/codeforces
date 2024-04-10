#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

//vector string deque break continue
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
#define int long long

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    vector <int> h(n);
    forn (i, 0, n) {
        cin >> h[i];
        h[i] %= (a + b);
        if (h[i] % a == 0)
            h[i] = (h[i] - 1 + a + b) % (a + b);
        h[i] /= a;
        //cout << h[i] << " ";
    }
    int ans = 0;
    sort(all(h));
    forn (i, 0, n) {
        if (k >= h[i])
            ans++;
        else
            break;
        k -= h[i];
    }
    cout << ans;
    return 0;
}