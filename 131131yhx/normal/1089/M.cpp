#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int V[11][11], n;

const int MxX = 18, MxY = 36, MxZ = 6; // Layer 0 is left blank

char ch[MxZ][MxX][MxY];

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            scanf("%d", &V[i][j]);
    for(int i = 1; i <= 9; i++) V[i][i] = 1;
    for(int i = 1; i <= 9; i++)
        for(int j = 1; j <= 9; j++)
            for(int k = 1; k <= 9; k++)
                if(V[j][i] && V[i][k]) V[j][k] = 1;
    memset(ch, '.', sizeof ch);
    memset(ch[3], '#', sizeof ch[3]);
    for(int i = 0; i < MxX; i++)
        for(int j = 0; j < MxY; j += 4)
            ch[4][i][j] = (ch[5][i][j] = '#');
    for(int i = 1; i <= n; i++)
        ch[4][0][i * 4 - 2] = '0' + i;
    for(int i = 1; i <= 9; i++)
        for(int j = 0; j < MxY; j++)
            ch[1][i * 2 - 1][j] = '#';
    for(int i = 1; i <= 9; i++)
        ch[2][i * 2 - 1][i * 4 - 2] = '#', ch[3][i * 2 - 1][i * 4 - 2] = '.';
    for(int i = 1; i <= 9; i++)
        for(int j = 1; j <= 9; j++)
            if(V[i][j])
                ch[3][j * 2 - 1][i * 4 - 3] = (ch[3][j * 2 - 1][i * 4 - 1] = '.');
    printf("%d %d %d\n", MxY, MxX, MxZ);
    for(int i = MxZ - 1; i >= 0; i--) {
        for(int j = 0; j < MxX; j++) {
            for(int k = 0; k < MxY; k++)
                putchar(ch[i][j][k]);
            putchar('\n');
        }
        putchar('\n');
    }
    return 0;
}
/*
 4
 0 1 0 1
 0 0 1 0
 0 1 0 0
 1 0 0 0
*/