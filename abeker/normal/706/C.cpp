#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

const int MAXN = 100005;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

int N;
int cost[MAXN];
ll dp[MAXN][2];
string s[MAXN][2];
char buff[MAXN];

string rev(string x) {
    reverse(x.begin(), x.end());
    return x;
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", cost + i);
        
    for (int i = 1; i <= N; i++) {
        scanf("%s", buff);
        s[i][0] = buff;
        s[i][1] = rev(s[i][0]);
    }
    
    memset(dp, INF, sizeof dp);
    dp[0][0] = dp[0][1] = 0;
    for (int i = 1; i <= N; i++) 
        for (int k = 0; k < 2; k++)
            for (int l = 0; l < 2; l++)
                if (s[i - 1][k] <= s[i][l]) 
                    dp[i][l] = min(dp[i][l], dp[i - 1][k] + l * cost[i]);
    
    ll sol = min(dp[N][0], dp[N][1]);
    printf("%I64d\n", sol > 1e14 ? -1 : sol);
    
    return 0;
}