#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100005;
const int INF = (int)2e9;

int N, M;
int C, H;
int x[MAXN], y[MAXN];
int val[2][2][MAXN];
int idx[2][2];

int main() {
    scanf("%d%d%d", &N, &M, &C);
    for (int i = 0; i < C; i++) {
        scanf("%d%d", x + i, y + i);
        for (int k = 0; k < 2; k++)
            for (int l = 0; l < 2; l++)
                val[k][l][i] = x[i] * (2 * k - 1) + y[i] * (2 * l - 1);
    }
    
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            idx[i][j] = max_element(val[i][j], val[i][j] + C) - val[i][j];
    
    scanf("%d", &H);
    int mini = INF, opt = 0;
    for (int i = 0; i < H; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        int maks = 0;
        for (int k = 0; k < 2; k++)
            for (int l = 0; l < 2; l++) 
                maks = max(maks, abs(a - x[idx[k][l]]) + abs(b - y[idx[k][l]]));
        if (maks < mini) {
            mini = maks;
            opt = i;
        }
    }
    
    printf("%d\n%d\n", mini, ++opt);
    
    return 0;
}