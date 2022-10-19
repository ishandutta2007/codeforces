#include <cstdio>
using namespace std;

const int MAXN = 5005;

int N, M, K;
int color[MAXN][2], last[MAXN][2];

int main() {
    scanf("%d%d%d", &N, &M, &K);
    for (int i = 0; i < K; i++) {
        int t, x, y;
        scanf("%d%d%d", &t, &x, &y);
        t--; x--;
        color[x][t] = y;
        last[x][t] = i + 1;
    }
    
    for (int i = 0; i < N; i++, puts(""))
        for (int j = 0; j < M; j++) 
            if (last[i][0] > last[j][1]) printf("%d ", color[i][0]);
            else if (last[i][0] < last[j][1]) printf("%d ", color[j][1]);
            else printf("0 ");
            
    return 0;
}