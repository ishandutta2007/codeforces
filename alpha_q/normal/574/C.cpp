#include <stdio.h>

using namespace std;

const int N = 100005;

int A[N], n, i, Base, Now, Flag;

int main () {
    scanf("%d", &n); Flag = true;
    for (i = 1; i <= n; i++) scanf("%d", A + i);

    Base = A[1];
    while (Base % 2 == 0) Base /= 2;
    while (Base % 3 == 0) Base /= 3;

    for (i = 2; i <= n; i++) {
        Now = A[i];
        while (Now % 2 == 0) Now /= 2;
        while (Now % 3 == 0) Now /= 3;
        if (Now != Base) {
            Flag = false;
            break;
        }
    }

    printf("%s\n", Flag ? "Yes" : "No");
    return 0;
}