#include <cstdio>
#include <set>
using namespace std;

const int MAXN = 1005;

int N, M;
char mat[MAXN][MAXN];

void load() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++)
        scanf("%s", mat[i]);
}

int solve() {
    set <int> S;
    for (int i = 0; i < N; i++) {
        int a, b;
        for (int j = 0; j < M; j++)
            if (mat[i][j] == 'G') a = j;
            else if (mat[i][j] == 'S') b = j;
        if (a > b) return -1;
        S.insert(b - a);
    }
    return S.size();
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}