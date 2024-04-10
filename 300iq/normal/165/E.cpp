#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fc first
#define sc second
#define ll long long
#define forn(i, n) for(int i = 0; i < (int) (n); i++)
#define fort(i, j, n) for (int i = j; i < (int) (n); i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

int main() {
    int lim = (1 << 22);
    vector <int> dp(lim, -1);
    int n;
    scanf("%d", &n);
    vector <int> a(n);
    for (auto &c : a) {
        scanf("%d", &c);
        dp[c] = c;
    }
    for (int mask = 0; mask < lim; mask++) {
        if (dp[mask] != -1) {
            for (int i = 0; i < 22; i++) {
                dp[mask | (1 << i)] = dp[mask];
            }
        }
    }
    for (auto c : a) {
        printf("%d ", dp[(~c) & (lim - 1)]);
    }
    puts("");
}