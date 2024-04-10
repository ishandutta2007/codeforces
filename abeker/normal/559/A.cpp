#include <cstdio>
using namespace std;

int a[10];

int sq(int x) {
    return x * x;
}

int main() {
    for (int i = 0; i < 6; i++) 
        scanf("%d", a + i);
    printf("%d\n", sq(a[0] + a[1] + a[2]) - sq(a[0]) - sq(a[2]) - sq(a[4]));
    return 0;
}