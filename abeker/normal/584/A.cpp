#include <cstdio>
using namespace std;

int main() {
    int N, T;
    scanf("%d%d", &N, &T);
    if (T < 10) {
        while (N--) printf("%d", T);
        puts("");
        return 0;
    }
    if (N == 1) {
        puts("-1");
        return 0;
    }
    printf("1");
    for (int i = 1; i < N; i++)
        printf("0");
    puts("");
    return 0;
}