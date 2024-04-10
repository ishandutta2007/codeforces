#include <cstdio>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    if (N % 2) {
        puts("0");
        return 0;
    }
    printf("%d\n", (N / 2 - 1) / 2);
    return 0;
}