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

int nxt() {
    int x;
    cin >> x;
    return x;
}

const int MOD = 998244353;

int add(int x, int y) {
    x += y;
    if (x >= MOD)
        return x - MOD;
    return x;
}

int sub(int x, int y) {
    x -= y;
    if (x < 0)
        return x + MOD;
    return x;
}

int mul(int x, int y) {
    return (1LL * x * y) % MOD;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    vector <int> p(20, 1);
    forn (i, 1, 20)
        p[i] = mul(p[i - 1], 10);
    int n = nxt();
    vector <int> a(n);
    int ans = 0;
    forn (i, 0, n) {
        int t = nxt();
        vector <int> b;
        while (t) {
            b.pb(t % 10);
            t /= 10;
        }
        //reverse(all(b));
        forn (j, 0, sz(b)) 
            ans = add(ans, mul(n, mul(b[j], add(p[2 * j + 1], p[2 * j]))));
    }
    cout << ans;
    return 0;
}