#include <cstdio>

using namespace std;

const int MAXN = 111;

int s[MAXN][MAXN];
int f[27];
int d[MAXN][MAXN];
int N, M, A, B, C, k;
int a, b, c;

int main()
{
    /*
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    //*/
    scanf("%d %d %d %d %d", &N, &M, &A, &B, &C);
    
    
    a = (N % 2) * M / 2;
    b = (M % 2) * N / 2;
    c = (N / 2) * (M / 2);
    
    if (
        ((N * M) & 1) ||
        a > A || b > B ||
        c > C + (A - a) / 2 + (B - b) / 2
    )
    {
        puts("IMPOSSIBLE");
        return 0;
    }
    
    for (int i = 1; i <= a; i++)
        d[N][2 * i - 1] = d[N][2 * i] = ++k;

    for (int i = 1; i <= b; i++)
        d[2 * i - 1][M] = d[2 * i][M] = ++k;
        

    A = (A - a) / 2;
    B = (B - b) / 2;
    for (int i = 2; i <= N; i += 2)
        for (int j = 2; j <= M; j += 2)
        {
            if (C)
            {
                d[i - 1][j - 1] = d[i - 1][j] = d[i][j - 1] = d[i][j] = ++k;
                C--;
            }
            else
            
            if (A)
            {
                d[i - 1][j - 1] = d[i - 1][j] = ++k;
                d[i][j - 1] = d[i][j] = ++k;
                A--;
            }
            else
            
            if (B)
            {
                d[i - 1][j - 1] = d[i][j - 1] = ++k;
                d[i - 1][j] = d[i][j] = ++k;
                B--;
            }
        }
        
    k = 0;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
        {
            if (s[i][j]) continue;
            int x1 = i - 1, y1 = j - 1, x2 = i + 1, y2 = j + 1;
            while (x2 <= N && d[i][j] == d[x2][j]) x2++;
            while (y2 <= M && d[i][j] == d[i][y2]) y2++;
            
            k++;
            if (1 <= y1) for (int z = x1 + 1; z < x2; z++) f[s[z][y1]] = k;
            if (y2 <= M) for (int z = x1 + 1; z < x2; z++) f[s[z][y2]] = k;
            if (1 <= x1) for (int z = y1 + 1; z < y2; z++) f[s[x1][z]] = k;
            if (x2 <= N) for (int z = y1 + 1; z < y2; z++) f[s[x2][z]] = k;
            
            s[i][j] = 1;
            while (f[s[i][j]] == k) s[i][j]++;
            
            for (int x = x1 + 1; x < x2; x++)
                for (int y = y1 + 1; y < y2; y++)
                    s[x][y] = s[i][j];
        }
        
    for (int i = 1; i <= N; i++, printf("\n"))
        for (int j = 1; j <= M; j++)
            printf("%c", s[i][j] - 1 + 'a');
    return 0;
}