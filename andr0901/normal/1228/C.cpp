#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

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

vector <int> get_primes(int x) {
    vector <int> primes;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            primes.pb(i);
            while (x % i == 0)
                x /= i;
        }
    }
    if (x > 1) 
        primes.pb(x);
    return primes;
}

const int MOD = 1e9 + 7;

int bin_pow(int a, int p) {
    if (!p)
        return 1;
    if (p % 2)
        return (1LL * bin_pow(a, p - 1) * a) % MOD;
    return (1LL * bin_pow(a, p / 2) * bin_pow(a, p / 2)) % MOD;
}

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int x, n;
    cin >> x >> n;
    auto primes = get_primes(x);
    int ans = 1;
    for (int i : primes) {
        //cout << i << " ";
        int y = i, cnt = 0;
        while (y <= n && i <= 1e9) {
            //cout << y << " ";
            cnt += n / y;
            if (y > (n + i - 1) / i)
                break;
            y *= i;
        }
        ans = (1LL * ans * bin_pow(i, cnt)) % MOD;
    }
    //cout << "\n";
    cout << ans;
    //forn (mask, 0, 1 << )
    return 0;
}