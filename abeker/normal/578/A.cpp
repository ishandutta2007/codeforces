#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    if (a < b) {
        puts("-1");
        return 0;
    }
    if (a == b) {
        printf("%d\n", a);
        return 0;
    }
    int k1 = (a - b) / b / 2; 
    int k2 = (a + b) / b / 2; 
    printf("%.12lf\n", min((double)(a - b) / (2 * k1), (double)(a + b) / (2 * k2)));  
    return 0;
}