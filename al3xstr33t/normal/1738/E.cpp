#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cassert>
#include <map>
#include <numeric>
#include <cstring>
#include <set>
#include <ctime>
#include <queue>
#include <cmath>
#include <iomanip>
#include <iterator>
#include <bitset>
#include <unordered_map>
#include <complex>
#include <unordered_set>
#include <chrono>
#include <random>
#include <functional>
#include <random>

using namespace std;

const int maxN = 100009;
int N, a[maxN], dp[maxN], coef[maxN];
bool ok[maxN];
long long s[maxN];
const int mod = 998244353;

int add (int x, int y) {int ans = x + y; if (ans >= mod) ans -= mod; return ans;}
int subtract (int x, int y) {if (x >= y) return x - y; return x - y + mod;}
int mul (int x, int y) {return 1LL * x * y % mod;}
void adto (int &x, int y) {x += y; if (x >= mod) x -= mod;}

int power (int a, int b)
{
    int p = 1;
    for (int i=0; (1<<i) <= b; i++)
    {
        if (b & (1 << i)) p = mul (p, a);
        a = mul (a, a);
    }
    return p;
}

int fac[2000009], inv[2000009];
void Prec (int lim){fac[0] = inv[0] = 1;for (int i=1; i<=lim; i++)fac[i] = mul (fac[i - 1], i);
inv[lim] = power (fac[lim], mod - 2);for (int i=lim - 1; i>=0; i--)inv[i] = mul (inv[i + 1], i + 1);}
int comb (int N, int K){if (K > N || N < 0 || K < 0) return 0; int ans = mul (fac[N], inv[N - K]);ans = mul (ans, inv[K]);return ans;}

int main() {
    //freopen("../input", "r", stdin);
    //freopen("../output", "w", stdout);
    int tests;
    scanf("%d", &tests);
    Prec(100009);
    while (tests --) {
        scanf("%d", &N);
        for (int i=1; i<=N; i++)
            scanf("%d", &a[i]), s[i] = s[i - 1] + a[i];
        if (s[N] == 0) {
            printf("%d\n", power(2, N - 1));
            continue;
        }
        int j = N;
        for (int i=0; i<=N; i++) {
            while (j > i && s[N] - s[j] < s[i])
                j --;
            if (j >= i && s[N] - s[j] == s[i] && s[i] < s[i + 1]) {
                ok[i] = 1;
                int cntN = 0, cntM = 0, p = i;
                while (s[p - 1] == s[p] && p > 0)
                    p --;
                cntN = i - p + 1;
                if (s[j] == s[i]) {
                    coef[i] = subtract(power(2, cntN), 1);
                    continue;
                }
                p = j;
                while (p > 0 && s[p - 1] == s[p])
                    p --;
                cntM = j - p + 1;
                if (s[i] == 0) cntN --;
                if (s[j] == s[N]) cntM --;
                coef[i] = 0;
                for (int k=1; k<=min(cntN, cntM); k++)
                    adto(coef[i], mul(comb(cntN, k), comb(cntM, k)));
            }
            else coef[i] = 0;
        }
        dp[0] = 1;
        int sumSoFar = 1, ans = 1;
        for (int i=1; i<=N; i++) {
            if (ok[i])
                dp[i] = mul(sumSoFar, coef[i]),
                adto(sumSoFar, dp[i]);
            else
                dp[i] = 0;
            if (s[i] <= s[N] - s[i]) adto(ans, dp[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}

/*
const int seed = time (0);
mt19937 gen (seed);
long long getRand(long long a, long long b) {return uniform_int_distribution < long long > (a, b) (gen);}
*/