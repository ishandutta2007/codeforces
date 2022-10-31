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

long long gcd(long long a, long long b) {
    if (!a)
        return b;
    return gcd(b % a, a);
}

void solve() {
    long long a, m;
    cin >> a >> m;
    long long g = gcd(a, m);
    a /= g, m /= g;
    long long ans = m;
    for (long long i = 2; i * i <= m; ++i) {
        if (m % i == 0) {
            while (m % i == 0)
                m /= i;
            ans -= ans / i;
        }
    }
    if (m > 1)
        ans -= ans / m;
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}