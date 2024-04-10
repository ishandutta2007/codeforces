#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
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

int nxt() {
    int x;
    cin >> x;
    return x;
}

int gcd(int a, int b) {
    if (!a)
        return b;
    return gcd(b % a, a);
}

int n;
vector <int> a, dp;

int solve(int x) {
    if (dp[x] != -1)
        return dp[x];
    dp[x] = 1;
    vector <bool> used(n);
    forn (i, 0, n) {
        int j = i, parity = 0;
        while (!used[j]) {
            used[j] = 1;
            parity += a[j];
            j = (j + x) % n;
        }
        if (parity % 2)
            dp[x] = 0;
    }
    return dp[x];
}

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    n = nxt();
    a.resize(n);
    forn (i, 0, n) {
        char c;
        cin >> c;
        a[i] = c - '0';
    }
    dp.resize(n + 1, -1);
    int ans = 0;
    forn (k, 0, n)      
        ans += solve(gcd(k, n));
    cout << ans;
    return 0;
}