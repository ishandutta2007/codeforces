#include <bits/stdc++.h>

using namespace std;

const int nmax = 100000 + 5;

int freq[nmax];

typedef long long int lint;
lint dp[nmax];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int v;
        cin >> v;
        ++freq[v];
    }

    for (int i = 100000; i >= 0; --i) {
        dp[i] = max(dp[i + 1], (i + 1LL) * freq[i + 1] + dp[i + 2]);
    }
    cout << dp[0] << endl;
    return 0;
}