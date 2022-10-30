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
    int a, b, c, d;
    int x, y;
    cin >> a >> b >> c >> d >> x >> y;
    if (x > y) {
    	int t = min(a, d);
    	a -= t, d -= t;
    	cout << t * x + min({b, c, d}) * y;
    } else {
    	int t = min({b, c, d});
    	b -= t, c -= t, d -= t;
    	cout << t * y + min(a, d) * x;
    }
    return 0;
}