#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 5005;
const int INF = 0x3f3f3f3f;

int N;
int a[MAXN];
int dp[MAXN][MAXN];
int suff[MAXN][MAXN];

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", a + i);
}

int solve() {
    memset(dp, -INF, sizeof dp);
    memset(suff, -INF, sizeof suff);
    
    for (int i = N - 1; i >= 0; i--) {
        int k = i + 1, sum = 0, tmp = 0;
        for (int j = i; j < N; j++) {
            sum += a[j];
            for (; k < N && tmp < sum; k++)
                tmp += a[k];
            if (j == N - 1) 
                dp[i][j] = 1;
            else if (tmp >= sum) 
                dp[i][j] = suff[j + 1][k - 1] + 1;
            tmp -= a[j + 1];
        }
        for (int j = N - 1; j >= i; j--)
            suff[i][j] = max(dp[i][j], suff[i][j + 1]);
    }  
    
    return N - *max_element(dp[0], dp[0] + N);
}
    
int main() {
    load();
    printf("%d\n", solve());
    return 0;
}