#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

const int Nmax = 100005;

vector<int> Vals[Nmax];
int A[Nmax], Lis[Nmax], MaxLen[Nmax];

char Ans[Nmax];

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

    int M = 0;
    for (int i = 1; i <= N; ++i) {
        int pos = lower_bound(Lis, Lis + M, A[i]) - Lis;
        if (pos == M) ++M;
        Lis[pos] = A[i];
        Vals[pos].push_back(i);

        MaxLen[i] = pos + 1;
    }

    M = 0;
    for (int i = N; i > 0; --i) {
        int pos = lower_bound(Lis, Lis + M, A[i], [](int a, int b) -> bool{return a > b;}) - Lis;
        if (pos == M) ++M;
        Lis[pos] = A[i];
        MaxLen[i] += pos;
    }

    for (int i = M - 1; i >= 0; --i) {
        int cnt = 0;
        for (int p: Vals[i])
            if (MaxLen[p] == M) ++cnt;

        for (int p: Vals[i])
            if (MaxLen[p] == M) Ans[p] = cnt == 1 ? '3': '2';
            else Ans[p] = '1';
    }

    printf("%s\n", Ans + 1);
}