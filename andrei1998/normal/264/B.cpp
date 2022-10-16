#include <iostream>
#include <vector>

using namespace std;

const int NMAX = 100005;

int v[NMAX];
int dp[NMAX];

int best[NMAX];

bool composite[NMAX];
vector <int> primes_that_divide[NMAX];

int main()
{
    ios_base :: sync_with_stdio(false);

    int n = 0;
    cin >> n;

    for (int i = 1; i <= n; ++ i)
        cin >> v[i];

    for (int i = 2; i <= 100000; ++ i)
        if (!composite[i])
            for (int j = i; j <= 100000; j += i) {
                composite[j] = true;
                primes_that_divide[j].push_back(i);
            }

    int ans = 1;
    for (int i = 1; i <= n; ++ i) {
        dp[i] = 1;
        for (auto it: primes_that_divide[v[i]])
            if (1 + best[it] > dp[i])
                dp[i] = 1 + best[it];

        for (auto it: primes_that_divide[v[i]])
            if (dp[i] > best[it])
                best[it] = dp[i];

        if (dp[i] > ans)
            ans = dp[i];

    }

    cout << ans << '\n';
    return 0;
}