#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 105;
const int INF = 0x3f3f3f3f;

int mini[MAXN];

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    memset(mini, INF, sizeof mini);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            int x;
            scanf("%d", &x);
            mini[i] = min(mini[i], x);
        }
    printf("%d\n", *max_element(mini, mini + N));
    return 0;
}