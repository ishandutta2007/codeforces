#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;
const int NMAX = 1000005;

int poss[20 * NMAX];
int add[NMAX];

int A[NMAX];
int changes[NMAX];

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        add[i] = i;
        poss[add[i]] = i;
    }
    
    int sub = 0;
    for (int i = 2; i <= n; ++i) {
        int cnt = 0;
        for (int j = 0; j < n; j += i) {
            int nmb = poss[sub + j];
            changes[cnt++] = nmb;
        }
        for (int j = 0; j < cnt; ++j) {
            int nmb = changes[j];
            add[nmb] += i;
            if (add[nmb] - sub - 1 >= n) {
                add[nmb] -= (add[nmb] - sub - n);
            }
            poss[add[nmb]] = nmb;
        }
        sub++;
    }

    for (int i = 0; i < n; ++i) {
        A[i] = poss[sub + i] + 1;
    }

    for (int i = 0; i < n; ++i) {
        printf("%d ", A[i]);
    }
    printf("\n");
}