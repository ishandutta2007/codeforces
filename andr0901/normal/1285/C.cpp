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

long long x;

long long ans = 1e18;
long long a, b;

long long gcd(long long a, long long b) {
    if (!a)
        return b;
    return gcd(b % a, a);
}

void check(long long y) {
    if (x / y * y != gcd(x / y, y) * x)
        return;
    if (max(x / y, y) < ans) {
        ans = max(x / y, y);
        a = x / y;
        b = y;
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> x;
    for (long long i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            check(i);
            check(x / i);
        }
    }
    cout << a << " " << b;
    return 0;
}