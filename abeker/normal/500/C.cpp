#include <cstdio>
using namespace std;

const int MAXN = 505;
const int MAXM = 1005;

int N, M;
int w[MAXN], last[MAXN];
int f[MAXM];

void update(int x, int val) {
    for (++x; x < MAXM; x += x & -x)
        f[x] += val;
}

int get(int x) {
    int ret = 0;
    for (++x; x; x -= x & -x) 
        ret += f[x];
    return ret;
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++)
        scanf("%d", w + i);
        
    int sol = 0;
    for (int i = 1; i <= M; i++) {
        int b; scanf("%d", &b); b--;
        sol += get(i) - get(last[b]);
        update(last[b], -w[b]);
        update(i, w[b]);
        last[b] = i;
    }
    
    printf("%d\n", sol);
    return 0;
}