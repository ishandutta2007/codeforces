#include <cstdio>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    int mini = (int)1e9;
    long long sum = 0;
    while (N--) {
        int x;
        scanf("%d", &x);
        if (x % 2 && x < mini) mini = x;
        sum += x;
    }
    if (sum % 2) sum -= mini;
    printf("%I64d\n", sum);
    return 0;
}