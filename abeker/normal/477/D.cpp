#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 5005;
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;

int N;
char s[MAXN];

void load() {
    scanf("%s", s + 1);
}

int ways[MAXN][MAXN];
int opt[MAXN][MAXN];
int seq[MAXN][MAXN];
int suff[MAXN];

inline bool cmp(int x, int len) {
    return seq[len][x] < len && s[x + seq[len][x]] > s[x + len + seq[len][x]]; 
}

void solve() {
    N = strlen(s + 1);
    
    int pow = 1;
    for (int i = N; i; i--) {
        suff[i] = (suff[i + 1] + pow * (s[i] - '0')) % MOD; 
        pow = 2 * pow % MOD;
    }
    
    for (int i = 1; i < N; i++) 
        for (int j = N - i; j; j--) 
            seq[i][j] = (seq[i][j + 1] + 1) * (s[j] == s[j + i]);
    
    int maks = 0, sol = INF;
    for (int i = 1; i <= N; i++) 
        for (int j = i; j; j--) {
            opt[i][j] = INF;
            if (j == 1) {
                ways[i][j] = 1;
                opt[i][j] = 1;
            }
            else if (s[j] == '1') {
                int pos = 2 * j - i - 1;
                if (pos < 1) 
                    pos = 1;
                else if (cmp(pos, i - j + 1))
                    pos++;
                ways[i][j] = ways[j - 1][pos];
                opt[i][j] = opt[j - 1][pos] + 1;
            }
            if (opt[i][j] < INF && i == N) {
                if (j + 20 < N) maks = max(maks, j);
                else sol = min(sol, suff[j] + opt[i][j]);
            }
            if (i == j) continue;
            ways[i][j] = (ways[i][j] + ways[i][j + 1]) % MOD;
            opt[i][j] = min(opt[i][j], opt[i][j + 1]); 
        } 
    
    if (sol == INF) 
        sol = (suff[maks] + opt[N][maks]) % MOD;
        
    printf("%d\n%d\n", ways[N][1], sol);                        
}

int main() {
    load();
    solve();
    return 0;
}