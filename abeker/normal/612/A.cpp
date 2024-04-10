#include <cstdio>
using namespace std;

const int MAXN = 105;

int N, P, Q;
char s[MAXN];

int main() {
    scanf("%d%d%d%s", &N, &P, &Q, s);
    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXN; j++)
            if (i * P + j * Q == N) {
                printf("%d\n", i + j);
                for (int k = 0; k < i; k++, puts(""))
                    for (int l = 0; l < P; l++)
                        printf("%c", s[k * P + l]);
                for (int k = 0; k < j; k++, puts(""))
                    for (int l = 0; l < Q; l++)
                        printf("%c", s[i * P + k * Q + l]);
                return 0;
            }    
    puts("-1");
    return 0;
}