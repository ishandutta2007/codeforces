#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;
const int NMAX = 1000005;

int A[NMAX];
int stk[NMAX];
bool closed[NMAX];

void noSol() {
    puts("NO");
    exit(0);
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &A[i]);
    }

    int m;
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i) {
        int x;
        scanf("%d", &x);
        closed[x] = true;
    }

    int top = 0;
    for (int i = n; i > 0; --i) {
        if (top == 0 || A[i] != stk[top - 1] || closed[i]) {
            stk[top++] = A[i];
            A[i] *= -1;
        } else {
            top--;
        }
    }

    if (top > 0) noSol();

    puts("YES");
    for (int i = 1; i <= n; ++i) {
        printf("%d ", A[i]);
    }
    puts("");
}