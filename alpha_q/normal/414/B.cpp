#include <bits/stdc++.h>

using namespace std;

const int MAX = 2005;
const int MOD = 1e9 + 7;

vector <long long> D[MAX];
long long DP[MAX][MAX], N, K;

void Div (void) {
    for (long long n = 1; n < MAX; n++) {
        for (long long i = 1; i * i <= n; i++)
            if (n % i == 0) {
                D[n].push_back(i);
                if (i * i != n) D[n].push_back(n/i);
            }
    }
}

long long Call (long long n, long long k) {
    if (DP[n][k] != -1) return DP[n][k];
    if (n == 1 or k == 1) return DP[n][k] = 1;

    DP[n][k] = 0;
    for (long long i = 0; i < D[n].size(); i++)
        DP[n][k] = (DP[n][k] + Call(D[n][i], k - 1)) % MOD;
    DP[n][k] %= MOD;

    return DP[n][k];
}

int main() {
    //freopen("input.txt", "r", stdin);

    Div();
    memset(DP, -1, sizeof DP);
    scanf("%I64d %I64d", &N, &K);

    long long Ret = 0;
    for (long long j = 1; j <= N; j++) Ret = (Ret + Call(j, K)) % MOD;

    printf("%I64d", Ret);
    return 0;
}