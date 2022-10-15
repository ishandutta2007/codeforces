#include <cstdio>
#include <map>

using namespace std;

const int MAXA = 40003;
const int MAXB = 33;

int a, b, A, B, n;
int f[MAXA][MAXB];

int main() {
/*
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
//*/
    scanf("%d %d %d", &A, &B, &n);

    for (int a = MAXA; --a; )
        for (int b = MAXB; --b; )
        {
            f[a][b] = 0;
        
            long long x = 1;
            for (int i = 0; i < b && x < n; i++)
                x *= a;
                
            if (x >= n)
            {
                f[a][b] = 1;
                continue;
            }
            
            if (
                (a < MAXA - 1 && f[a + 1][b] == 0) ||
                (b < MAXB - 1 && f[a][b + 1] == 0) 
            ) f[a][b] = 1;
            
            else
            
                if (
                    (a < MAXA - 1 && f[a + 1][b] == -1) ||
                    (b < MAXB - 1 && f[a][b + 1] == -1) ||
                    (a == 1 && b == MAXB - 1)
                ) f[a][b] = -1;
                
            if (a == MAXA - 1 && b == 1 && (1 - ((a + n) & 1)))
                f[a][b] = 1;
        }

    switch (f[A][B])
    {
        case 1: puts("Masha"); break;
        case 0: puts("Stas"); break;
        case -1: puts("Missing"); break;
    }
    return 0;
}