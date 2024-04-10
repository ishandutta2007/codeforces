#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long ll;

const int MAXN = 505;
const ll INF = (ll)1e18;

int N;
int x, y;
ll mat[MAXN][MAXN];
ll row[MAXN], col[MAXN];
ll d1, d2;

void calc() {
    d1 = d2 = 0;
    for (int i = 0; i < N; i++) 
        row[i] = col[i] = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            row[i] += mat[i][j];
            col[j] += mat[i][j];
        }
    for (int i = 0; i < N; i++) {
        d1 += mat[i][i];
        d2 += mat[i][N - i - 1];
    }
}

void bye() {
    puts("-1");
    exit(0);
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            scanf("%I64d", mat[i] + j);
            if (mat[i][j]) continue;
            x = i;
            y = j;
        }
    
    if (N == 1) {
        puts("1");
        return 0;
    }
    
    calc();
    
    for (int i = 0; i < N; i++) 
        if (i != x) {
            mat[x][y] = row[i] - row[x];
            break;
        }
    
    calc();
    
    if (mat[x][y] <= 0 || mat[x][y] > INF || d1 != d2) bye();
    for (int i = 0; i < N; i++)
        if (row[i] != d1 || col[i] != d1) bye();
        
    printf("%I64d\n", mat[x][y]);
    
    return 0;
}