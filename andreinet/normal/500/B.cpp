#include <algorithm>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

const int Nmax = 305;

char Can[Nmax][Nmax];
int A[Nmax];

bool used[Nmax];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    int N;
    scanf("%d", &N);

    for (int i = 1; i <= N; ++i)
        scanf("%d", &A[i]);

    scanf("\n");
    for (int i = 1; i <= N; ++i)
        fgets(Can[i] + 1, Nmax, stdin);

    for (int i = 1; i <= N; ++i) {
        queue<int> Q;
        Q.push(i);

        memset(used, false, sizeof used);
        used[i] = true;
        while (!Q.empty()) {
            int node = Q.front();
            Q.pop();

            for (int j = 1; j <= N; ++j) {
                if (Can[node][j] == '1' && !used[j]) {
                    used[j] = true;
                    Q.push(j);
                }
            }
        }

        int minp = i;
        for (int j = i + 1; j <= N; ++j)
            if (used[j] && A[j] < A[minp])
                minp = j;

        swap(A[minp], A[i]);
    }

    for (int i = 1; i <= N; ++i)
        printf("%d ", A[i]);
    puts("");
}