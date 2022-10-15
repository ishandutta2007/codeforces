#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

ll n;
set<ll> primes;

int main() {
    boost();

    cin >> n;
    ll m = n;

    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            primes.insert(i);
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) primes.insert(n);

    /*if (*primes.begin() == 2) {
        if (primes.size() == 1) {
            printf("%lld\n", m / 2);
        } else {
            printf("1\n");
        }
        return 0;
    }*/

    if (primes.size() == 1) {
        printf("%lld\n", *primes.begin());
    } else {
        printf("1\n");
    }

    return 0;
}