#include <cstdio>
#include <cstdlib>
using namespace std;

void bye() {
    puts("-1");
    exit(0);
}

int main() {
    int N, D, H;
    scanf("%d%d%d", &N, &D, &H);
    
    if (D > 2 * H) bye();
    
    if (H == 1 && D == 1 && N > 2) bye();
    
    for (int i = 0; i < H; i++)
        printf("%d %d\n", i + 1, i + 2);
    
    if (D > H) {
        printf("1 %d\n", H + 2);
        for (int i = 1; i < D - H; i++)
            printf("%d %d\n", H + i + 1, H + i + 2); 
    }
    
    for (int i = 1; i < N - D; i++)
        printf("%d %d\n", H, D + i + 1);
    
    return 0;
}