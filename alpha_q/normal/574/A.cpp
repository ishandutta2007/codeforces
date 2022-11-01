#include <stdio.h>
#include <algorithm>

using namespace std;

const int N = 102;

int n, A[N], i, Ret;

bool compare (int x, int y) {return x > y;}

int main () {
    scanf("%d", &n); Ret = 0;
    for (i = 1; i <= n; i++) scanf("%d", A + i);
    sort (A + 2, A + 1 + n, compare);
    while (A[2] >= A[1]) {
        --A[2], ++A[1], ++Ret;
        sort (A + 2, A + 1 + n, compare);
    }
    printf("%d\n", Ret);
    return 0;

}