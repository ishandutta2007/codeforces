#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

struct pi_func {
    int low_N, low_K;
    vector< vector<ll> > dp;
    vector<bool> sieve;
    vector<int> last_prime;
    vector<ll> primes;
    int limit = 1000000;

    void precalc(int _n, int _k, int _limit = 1000000) {
        ll i, j;

        low_N = _n;
        low_K = _k;
        limit = _limit;

        dp = vector< vector<ll> >(low_N + 3, vector<ll>(low_K + 3, 0));

        // compute primes
        primes.clear();
        sieve = vector<bool>(limit + 3, false);
        last_prime = vector<int>(limit + 3, 0);

        for (i = 2; i <= limit; i++) {
            last_prime[i] = last_prime[i - 1];
            if (sieve[i]) continue;

            last_prime[i]++;
            primes.pb(i);
            for (j = i * i; j <= limit; j += i) sieve[j] = true;
        }

        if (primes.size() < low_K) {
            cerr << "low_K is too big..";
            exit(0);
        }

        // compute dp
        for (i = 1; i <= low_N; i++) {
            dp[i][1] = i;

            for (j = 2; j <= low_K; j++)
                dp[i][j] = dp[i][j - 1] - dp[i / primes[j - 2]][j - 1];
        }
    }

    ll compute(ll n, ll k) {
        if (n < primes[k - 1]) return 1;
        if (k == 1) return n;
        if (n <= low_N && k <= low_K) return dp[n][k];

        return compute(n, k - 1) - compute(n / primes[k - 2], k - 1);
    }

    ll Lehmer(ll n) {
        if (n <= limit)
            return last_prime[n] + 1;

        int r2 = sqrt(n);
        int r3 = cbrt(n);

        int pos = last_prime[r3] + 1;
        ll ans = compute(n, pos) + pos - 1;

        for (int i = pos; primes[i - 1] <= r2; i++)
            ans -= Lehmer(n / primes[i - 1]) - i;

        return ans;
    }

    // consider 1 as being prime
    ll pi(ll n) {
        ll sq = sqrt(n);
        int pos = last_prime[sq] + 1;

        return compute(n, pos) + pos - 1;
    }

};

ll n, i;
pi_func L;
ll ans;

int main()
{
    //freopen("test.in","r",stdin);

    L.precalc(100000, 100);
    scanf("%lld", &n);

    int cnt = 1;
    for (auto e : L.primes) {
        if (1LL * e * e * e <= n) ans++;
        if (1LL * e * e > n) break;

        ans += L.Lehmer(n / e) - (++cnt);
    }

    printf("%lld", ans);


    return 0;
}