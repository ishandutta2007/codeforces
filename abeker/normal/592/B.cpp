#include <cstdio>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    printf("%I64d\n", (long long)(N - 1) * (N - 3) + 1);
    return 0;
}