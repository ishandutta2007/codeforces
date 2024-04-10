#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int NMAX = 5000 + 5;

int v[NMAX];
int dp[NMAX];
pair <int, int> vals[NMAX];

bool freq[NMAX];

int main()
{
    for (int i = 0; i <= 5002; ++ i)
        vals[i] = make_pair(10000, -5000);

    int N;
    cin >> N;

    for (int i = 1; i <= N; ++ i) {
        cin >> v[i];
        vals[v[i]] = make_pair(min(vals[v[i]].first, i), i);
    }

    for (int i = 1; i <= N; ++ i) {
        dp[i] = dp[i - 1];

        pair <int, int> aux(10000, -5000);
        memset(freq, 0, sizeof freq);
        int xorr = 0;
        for (int j = i; j; -- j) {
            if (!freq[v[j]]) {
                xorr ^= v[j];
                freq[v[j]] = true;
            }
            aux = make_pair(min(vals[v[j]].first, aux.first), max(vals[v[j]].second, aux.second));

            if (j <= aux.first && aux.second <= i)
                dp[i] = max(dp[i], xorr + dp[j - 1]);
        }
    }

    cout << dp[N] << '\n';
    return 0;
}