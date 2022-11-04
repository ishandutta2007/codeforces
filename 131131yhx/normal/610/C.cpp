#include <cstdio>
#include <cstring>
#include <algorithm>
#define M 1025

using namespace std;

bool K[M][M];

int main()
{
    int k;
    scanf("%d", &k);
    K[1][1] = 0;
    for(int i = 1; i <= k; i++)
    {
        int b = (1 << i >> 1);
        for(int j = 1; j <= b; j++)
            for(int k = 1; k <= b; k++)
                K[j + b][k] = K[j][k], K[j + b][k + b] = K[j][b + 1 - k], K[j][k + b] = !K[j + b][k + b];
    }
    for(int i = 1; i <= (1 << k); i++)
    {
        for(int j = 1; j <= (1 << k); j++)
            if(K[i][j]) putchar('+');
            else putchar('*');
        putchar('\n');
    }
    return 0;
}