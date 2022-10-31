#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define ll long long
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define int long long

int get(int x) {
    int ans = 1;
    while (x) {
        ans *= x % 10;
        x /= 10;
    }
    return ans;
}

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    int _n = n;
    int ans = get(n), idx = n;
    int cur = 1;
    while (n) {
        if (get(n - 1) * cur > ans)
            ans = get(n - 1) * cur, idx = n - 1;
        n /= 10;
        cur *= 9;
    }
    while (10 * idx + 9 <= _n) {
        idx = 10 * idx + 9;
    }
    cout << get(idx);
    return 0;
}