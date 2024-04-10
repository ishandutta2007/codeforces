#include <algorithm>
#include <cstdio>

using namespace std;

const int Valmax = 1000005;

int Next[Valmax], Prev[Valmax];
bool exists[Valmax];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    int N;
    scanf("%d", &N);

    for (int i = 1; i <= N; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        Next[x] = y;
        Prev[y] = x;
        exists[x] = exists[y] = true;
    }

    vector<int> order(N);
    for (int i = 1, j = Next[0]; i < N; i += 2) {
        order[i] = j;
        j = Next[j];
    }

    int pos = 0;
    for (int i = 1; i < Valmax; ++i) {
        if (exists[i] && !Prev[i] && Next[0] != i) {
            pos = i;
            break;
        }
    }

    for (int i = 0; i < N; i += 2) {
        order[i] = pos;
        pos = Next[pos];
    }

    for (int p: order)
        printf("%d ", p);
    puts("");
}