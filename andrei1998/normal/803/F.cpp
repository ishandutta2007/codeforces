#include <iostream>
#include <vector>

using namespace std;

const int NMAX = 100000 + 5;
const int MOD = 1000000000 + 7;

int put2[NMAX];
int freq[NMAX];

vector <int> primes;
int low[NMAX];
int mob[NMAX];

void sieve() {
    mob[1] = 1;
    for (int i = 2; i <= 100000; ++ i) {
        if (!low[i]) {
            low[i] = i;
            mob[i] = -1;
            primes.push_back(i);
        }
        for (int j = 0; j < primes.size() && primes[j] <= i && i * primes[j] <= 100000; ++ j) {
            low[i * primes[j]] = primes[j];
            if (low[i] != primes[j])
                mob[i * primes[j]] = mob[i] * (-1);
        }
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    put2[0] = 1;
    for (int i = 1; i <= N; ++ i)
        put2[i] = (2LL * put2[i - 1]) % MOD;
    for (int i = 1; i <= N; ++ i) {
        int val;
        cin >> val;
        ++ freq[val];
    }

    for (int i = 1; i <= 100000; ++ i)
        for (int j = 2 * i; j <= 100000; j += i)
            freq[i] += freq[j];

    sieve();

    int ans = 0;
    for (int i = 1; i <= 100000; ++ i)
        if (freq[i] && mob[i]) {
            ans += mob[i] * (put2[freq[i]] - 1);
            if (ans < 0)
                ans += MOD;
            if (ans >= MOD)
                ans -= MOD;
        }

    cout << ans << '\n';
    return 0;
}