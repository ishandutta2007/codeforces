#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define M 5050
#define mod 1000000007ll
#define INF 1000000000

int n, s[M];
int lcp[M][M];
long long d[M][M], sum[M][M];

void read() {
    string str;
    cin >> str;
    n = str.length();
    for (int i = 0; i < n; ++i)
        s[i] = str[i] - '0';
}

void calcLCP() {
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= n; ++j)
            lcp[i][j] = 0;

    for (int i = n - 1; i >= 0; --i)
        for (int j = n - 1; j >= 0; --j)
            if (s[i] == s[j]) {
                lcp[i][j] = lcp[i + 1][j + 1] + 1;
            } else {
                lcp[i][j] = 0;
            }
}

bool cmp(int i, int j, int len) {
    if (len <= lcp[i][j])
        return false;
    int p = lcp[i][j];
    return s[i + p] < s[j + p];
}

void din() {
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= n; ++j)
            d[i][j] = sum[i][j] = 0;

    d[0][0] = 1;
    for (int j = 0; j <= n; ++j)
        sum[0][j] = 1;


    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            if (s[i - j] == 0) {
                continue;
            }
            d[i][j] = sum[i - j][j - 1];
            if (i >= 2 * j && !cmp(i - j, i - 2 * j, j))
                d[i][j] += d[i - j][j];
            d[i][j] %= mod;
        }

        sum[i][0] = 0;
        for (int j = 1; j <= n; ++j)
            sum[i][j] = (sum[i][j - 1] + d[i][j]) % mod;
    }

    cout << sum[n][n] << "\n";
}

long long getRealAns(int k) {
    long long ans = 0;

    for (int i = n - k; i < n; ++i)
        ans = (2 * ans + s[i]) % mod;

    ans = (ans + d[n][k]) % mod;

    return ans;
}

void dinM() {
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= n; ++j)
            d[i][j] = sum[i][j] = INF;



    d[0][0] = 0;
    for (int j = 0; j <= n; ++j)
        sum[0][j] = 0;


    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            if (s[i - j] == 0) {
                continue;
            }

            d[i][j] = min(d[i][j], sum[i - j][j - 1] + 1);
            if (i >= 2 * j && !cmp(i - j, i - 2 * j, j))
                d[i][j] = min(d[i][j], d[i - j][j] + 1);
        }

        sum[i][0] = INF;
        for (int j = 1; j <= n; ++j)
            sum[i][j] = min(sum[i][j - 1], d[i][j]);
    }  

    int k = 0;
    while (d[n][k] >= INF)
        ++k;

    long long ans = getRealAns(k);

    while (k <= 23 && k <= n) {
        if (d[n][k] < INF)
            ans = min(ans, getRealAns(k));
        ++k;
    }

    cout << ans << "\n";
}

int main() {
#ifdef TROLL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);

    read();
    calcLCP();
    din();
    dinM();

    return 0;
}