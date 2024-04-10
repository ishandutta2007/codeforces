#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 2000005;
const int MOD = 1000000007;

int N, K;
char t[MAXN];
int dp[30];
int last[30];
int idx[30];
int cnt[MAXN];

inline int add(int x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
    return x;
}

void load() {
    scanf("%d%d%s", &N, &K, t);
}

bool cmp(const int &l, const int &r) {
    return last[l] < last[r];
}

int solve() {
    int M = strlen(t);
    memset(last, -1, sizeof last);
    for (int i = 0; i < M; i++) {
        int sum = 1;
        for (int j = 0; j < K; j++)
            sum = add(sum, dp[j]);
        dp[t[i] - 'a'] = sum;
        last[t[i] - 'a'] = i;
    }
    
    for (int i = 0; i < K; i++)
        idx[i] = i;
    sort(idx, idx + K, cmp);
    
    for (int i = 0; i < K; i++)
        cnt[i] = dp[idx[i]];
    
    for (int i = 0; i <= N; i++) {
        cnt[K + i] = 1;
        for (int j = 1; j <= K; j++)
            cnt[K + i] = add(cnt[K + i], cnt[K + i - j]); 
    }
    
    return cnt[N + K];
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}