#include <algorithm>
#include <cstdio>

using namespace std;

const int Nmax = 30005;

int A[Nmax];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    int N, M;
    scanf("%d%d", &N, &M);

    for (int i = 1; i < N; ++i)
        scanf("%d", &A[i]);

    bool ok = false;
    int i;
    for (i = 1; i < N; i += A[i])
        if (i == M)
            ok = true;

    if (i == M) ok = true;

    puts(ok ? "YES\n": "NO\n");
}