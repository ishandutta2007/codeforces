#include <cstdio>
using namespace std;

int main() {
    int h1, h2, a, b;
    scanf("%d%d%d%d", &h1, &h2, &a, &b);
    h2 -= h1 + 8 * a;
    if (h2 <= 0) {
        puts("0");
        return 0;
    }
    
    if (a <= b) {
        puts("-1");
        return 0;
    }
    
    int day = 12 * (a - b);
    
    printf("%d\n", (h2 - 1) / day + 1);
    
    return 0;
}