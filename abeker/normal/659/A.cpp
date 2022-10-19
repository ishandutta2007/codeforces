#include <cstdio>
using namespace std;

int main() {
    int N, A, B;
    scanf("%d%d%d", &N, &A, &B);
    printf("%d\n", ((A - 1 + B) % N + N) % N + 1);
    return 0;
}