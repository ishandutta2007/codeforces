#include <cstdio>
using namespace std;

const int MAXN = 55;

int N;
int a[MAXN][MAXN];
int p[MAXN];
bool bio[MAXN];

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", a[i] + j);
    
    for (int k = 1; k <= N; k++)
        for (int i = 0; i < N; i++) {
            if (bio[i]) continue;
            int cnt = 0;
            for (int j = 0; j < N; j++)
                cnt += a[i][j] == k;
            if (cnt == N - k) {
                p[i] = k;
                bio[i] = true;
                break;
            }
        }
        
    for (int i = 0; i < N; i++)
        printf("%d ", p[i]);
    puts("");
    return 0;
}