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

const int MAXN = (int) 3e6 + 7;
int cnt[MAXN];
ll dp[MAXN];

int main() {
    int n, m, x;
    scanf("%d", &n);
    forn (i, n) {
        scanf("%d", &x);
        cnt[x]++;
    }
    for (int i = 1; i < MAXN; i++) {
        for (int j = i; j < MAXN; j += i) {
            if (i == j / i) {
                dp[j] += cnt[i] * (ll) (cnt[i] - 1);
            } else {
                dp[j] += cnt[i] * (ll) cnt[j / i];
            }
        }
    }
    for (int i = 1; i < MAXN; i++) {
        dp[i] += dp[i - 1];
    }
    scanf("%d", &m);
    forn (i, m) {
        scanf("%d", &x);
        printf("%lld\n", n * (ll) (n - 1) - dp[x - 1]);
    }
    
}