#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")

#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = double;
using pii = pair<int, int>;
using uint = unsigned int;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;

void solve();

int main() {
#ifdef LOCAL
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(12) << fixed;
    cerr << setprecision(12) << fixed;  

    int tests = 1;
    // cin >> tests;

    while (tests--) {
        solve();
    }

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}

// -----------------------------------------------------------------


vector<int> primes;
vector<int> minPrime;

void sieve(int n) {
    minPrime.resize(n + 1);
    for (int i = 2; i <= n; ++i) {
        minPrime[i] = i;
    }
    for (int i = 2; i <= n; ++i) {
        if (minPrime[i] == i) {
            primes.push_back(i);
        }
        for (int p : primes) {
            if (p > minPrime[i] || (ll)i * p > n) {
                break;
            }
            minPrime[p * i] = p;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    int m = 5000;
    vector<int> cnt(m + 1);
    sieve(m);

    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        // k = 5000;
        ++cnt[k];
    }

    vector<int> vct(sz(primes));
    vector<int> pref_vct(sz(primes) + 1);

    vector<vector<int>> arr(m + 1, vector<int>(sz(primes)));
    vector<vector<int>> pref_arr(m + 1, vector<int>(sz(primes) + 1));
    vector<int> ptr(m + 1, sz(primes) - 1);

    ll dist = 0;
    for (int i = 0; i <= m; ++i) {
        for (int k = 0; k < sz(primes); ++k) {
            int p = primes[k];
            for (int x = i / p; x > 0; x /= p) {
                arr[i][k] += x;
            }
            pref_arr[i][k + 1] = arr[i][k] + pref_arr[i][k];
        }
        dist += ll(cnt[i]) * pref_arr[i].back();
    }

    for (int k = sz(primes) - 1; k >= 0; --k) {
        vector<int> dir(arr[m][k] + 1);
        ll sum = 0;
        ll add = 0;

        for (int i = 0; i <= m; ++i) {
            if (ptr[i] == k) {
                dir[0] += -cnt[i];
                dir[arr[i][k]] += 2 * cnt[i];
            } else {
                dir[0] += cnt[i];
            }
        }

        for (int i = 0; i < sz(primes); ++i) {
            pref_vct[i + 1] = pref_vct[i] + vct[i];
        }
        for (int i = 0; i <= m; ++i) {
            int x = 0;
            if (vct[k] == arr[i][k] && ptr[i] == k) {
                x = pref_arr[i][k] + pref_vct[k];
            } else {
                x = pref_arr[i][ptr[i]] + pref_vct[ptr[i]] + abs(arr[i][ptr[i]] - vct[ptr[i]]);
            }
            sum += ll(cnt[i]) * x;
        }

        add = dir[0];
        for (int alpha = 1; alpha <= arr[m][k]; ++alpha) {
            ++vct[k];

            sum += add;
            add += dir[alpha];

            if (sum >= dist) {
                --vct[k];
                break;
            }

            dist = sum;
        }

        for (int i = 0; i <= m; ++i) {
            if (ptr[i] == k && vct[k] == arr[i][k]) {
                --ptr[i];
            }
        }
    }

    cout << dist << endl;
}