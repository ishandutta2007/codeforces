#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 30000;
const int MAXM = 30000;
const int MAXK = 200000;
const int SIGMA = 26;

char s[1 + MAXK];
int have[SIGMA];
bool dp[1 + MAXK];

bool Check0(int n, int m, int k) {
    for (int i = 1; i <= k; i++)
        dp[i] = false;
    dp[0] = true;
    int sum = 0;
    for (int j = 0; j < SIGMA; j++) {
        sum += have[j];
        for (int i = k; i >= have[j]; i--)
            if (dp[i - have[j]])
                dp[i] = true;
    }
    int i = n;
    while (!dp[i])
        i++;
    if (sum - i >= m)
        return true;
    return false;
}

int Try(int n, int m, int ch) {
    for (int i = 1; i <= n; i++)
        dp[i] = false;
    dp[0] = true;
    int sum = 0;
    for (int j = 0; j < SIGMA; j++)
        if (j != ch) {
            sum += have[j];
            for (int i = n; i >= have[j]; i--)
                if (dp[i - have[j]])
                    dp[i] = true;
        }
    int answer = n * m;
    for (int i = 0; i <= n; i++)
        if (dp[i]) {
            int f1 = n - i, f2 = max(0, m - (sum - i));
            if (f1 + f2 <= have[ch])
                answer = min(answer, f1 * f2);
        }
    return answer;
}

int main() {
    //freopen("J.in", "r", stdin);
    //freopen("J.out", "w", stdout);
    int tests;
    scanf("%d", &tests);
    for (int test = 1; test <= tests; test++) {
        int n, m, k;
        scanf("%d%d%d\n%s", &n, &m, &k, s + 1);
        memset(have, 0, sizeof(have));
        for (int i = 1; i <= k; i++)
            have[s[i] - 'A']++;
        if (Check0(n, m, k)) {
            printf("0\n");
            continue;
        }
        int answer = n * m;
        for (int common = 0; common < SIGMA; common++)
            answer = min(answer, Try(n, m, common));
        printf("%d\n", answer);
    }
    return 0;
}