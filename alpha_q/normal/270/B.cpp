#include <bits/stdc++.h>

using namespace std;

int main (int argc, const char *argv[]) {
    int n, A[100005];
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", A + i);
    int j = n;
    while (j > 1 and A[j] > A[j - 1]) j--;
    printf("%d\n", j - 1);
    return 0;
}