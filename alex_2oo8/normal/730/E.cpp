#include <bits/stdc++.h>

using namespace std;

const int MX = 100;

int A[MX], B[MX];

int f(int i, int j) {
    int res = 0;
    if ((make_pair(A[i], -i) < make_pair(A[j], -j)) != (make_pair(B[i], -i) < make_pair(A[j], -j))) res++;
    if ((make_pair(A[j], -j) < make_pair(B[i], -i)) != (make_pair(B[j], -j) < make_pair(B[i], -i))) res++;

    return res;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", A + i, B + i);
        B[i] += A[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            ans += max(f(i, j), f(j, i));

    printf("%d\n", ans);

    return 0;
}