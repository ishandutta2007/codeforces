#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int Nmax = 1005;

int A[Nmax], B[Nmax];
int S[Nmax], Last[Nmax], Used[Nmax];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    int N, M;
    scanf("%d%d", &N, &M);

    for (int i = 1; i <= N; ++i)
        scanf("%d", &A[i]);
    for (int i = 1; i <= M; ++i)
        scanf("%d", &B[i]);

    long long sum = 0;
    for (int i = 1; i <= M; ++i) {
        memset(Used, 0, sizeof Used);
        for (int j = Last[B[i]] + 1; j < i; ++j) {
            if (!Used[B[j]]) {
                Used[B[j]] = 1;
                sum += A[B[j]];
            }
        }
        Last[B[i]] = i;
    }

    printf("%I64d\n", sum);
}