#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

int n, tmp[200010], Ans[200010];

double A[200010], B[200010];

bool cmp(int x, int y) {
    return A[x] * B[y] < A[y] * B[x] - 1e-10;
}

int main() {
    scanf("%d\n", &n);
    for(int i = 1; i <= n; i++) {
        tmp[i] = i;
        double a, b, c;
        scanf("(%lf+%lf)/%lf\n", &a, &b, &c);
        A[i] = a + b, B[i] = c;
    }
    sort(tmp + 1, tmp + n + 1, cmp);
    for(int i = 1, lst = 1; i <= n; lst = i) {
        while(i <= n && !cmp(tmp[i], tmp[lst]) && !cmp(tmp[lst], tmp[i])) i++;
        for(int j = lst; j < i; j++) Ans[tmp[j]] = i - lst;
    }
    for(int i = 1; i <= n; i++) printf("%d\n", Ans[i]);
}