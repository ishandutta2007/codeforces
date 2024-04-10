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
    int n;
    cin >> n;
    map <int, int> fs, sc;
    map <pii, int> a;
    forn (i, 0, n) {
        int x, y;
        cin >> x >> y;
        a[{x, y}]++;
        fs[x]++, sc[y]++;
    }
    vector <int> f(n + 1, 1);
    forn (i, 1, n + 1) 
        f[i] = mul(f[i - 1], i);
    int ans = f[n];
    int prod = 1;
    for (auto i : fs)
        prod = mul(prod, f[i.sc]);
    //cout << prod << " ";
    ans = sub(ans, prod);
    prod = 1;
    for (auto i : sc)
        prod = mul(prod, f[i.sc]);
    //cout << prod << " ";
    ans = sub(ans, prod);
    prod = 1;
    int prev = INT_MIN;
    for (auto i : a) {
        if (i.fs.sc < prev)
            prod = 0;
        prod = mul(prod, f[i.sc]);
        prev = i.fs.sc;
    }
    //cout << prod << " ";
    ans = add(ans, prod);
    cout << ans;
    return 0;
}