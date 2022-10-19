#include <cstdio>
#include <algorithm>
using namespace std;

int t, a[5];

int main() {
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d%d%d%d", &a[0], &a[1], &a[2], &a[3]);
        sort(a, a+4);
        printf("%d\n", min(a[0], a[1]) * min(a[2], a[3]));
    }
}