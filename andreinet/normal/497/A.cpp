#include <algorithm>
#include <cstdio>

using namespace std;

const int Nmax = 1005;

char A[Nmax][Nmax];
bool B[Nmax];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    int N, M;
    scanf("%d %d\n", &N, &M);

    for (int i = 1; i <= N; ++i)
        fgets(A[i] + 1, Nmax, stdin);

    int ans = 0;

    B[1] = true;
    for (int j = 1; j <= M; ++j) {
        bool ok = true;
        for (int i = 1; i <= N; ++i) {
            if (A[i][j] < A[i - 1][j] && !B[i]) {
                ok = false;
                break;
            }
        }

        if (!ok) ++ans;
        else {
            for (int i = 1; i <= N; ++i) {
                if (A[i][j] > A[i - 1][j])
                    B[i] = true;
            }
        }
    }

    printf("%d\n", ans);
}