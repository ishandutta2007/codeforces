#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 45;

int N, M, Q;
char mat[MAXN][MAXN];
int h[MAXN][MAXN];
int dp[MAXN][MAXN][MAXN][MAXN];

void load() {
    scanf("%d%d%d", &N, &M, &Q);
    for (int i = 1; i <= N; i++) 
        scanf("%s", mat[i] + 1);
}

int get(pii p) {
    return p.first * p.second;
}

void solve() {
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++) 
            if (mat[i][j] == '0') 
                h[i][j] = h[i - 1][j] + 1;
    
    for (int i = 1; i <= N; i++) 
        for (int k = i; k <= N; k++)
            for (int j = 1; j <= M; j++) {
                stack <pii> S;
                int sum = 0;
                for (int l = j; l <= M; l++) {
                    int cnt = 1, tmp = min(h[k][l], k - i + 1);
                    for (; !S.empty() && S.top().first > tmp; S.pop()) {
                        cnt += S.top().second;
                        sum -= get(S.top());
                    }
                    S.push(pii(tmp, cnt));
                    sum += get(S.top());
                    dp[i][j][k][l] = dp[i][j][k][l - 1] + dp[i][j][k - 1][l] - dp[i][j][k - 1][l - 1] + sum;
                }
            }
               
    while (Q--) {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        printf("%d\n", dp[a][b][c][d]);
    }           
}

int main() {
    load();
    solve();
    return 0;
}