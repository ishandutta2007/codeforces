#include <cstdio>
using namespace std;

int main() {
    int A, B;
    scanf("%d%d", &A, &B);
    int N = A + B + 1;
    for (int i = 1; i <= A; i++) 
        printf("%d ", i);
    printf("%d ", N);
    for (int i = 1; i <= B; i++) 
        printf("%d ", N - i);
    puts("");
    return 0;
}