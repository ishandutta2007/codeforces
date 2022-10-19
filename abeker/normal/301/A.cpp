#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    int neg = 0, sum = 0;
    int mini = 1005;
    for (int i = 1; i < 2 * N; i++) {
        int x;
        scanf("%d", &x);
        neg ^= x < 0;
        x = abs(x);
        mini = min(mini, x); 
        sum += x;
    }
    printf("%d\n", sum - (neg && !(N % 2) ? 2 * mini : 0));
    return 0;
}