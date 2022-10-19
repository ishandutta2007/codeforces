#include <cstdio>
using namespace std;

typedef long long ll;

const int MAXN = 55;

int N;
ll K;
ll f[MAXN];

void load() {
    scanf("%d%I64d", &N, &K);
}

void solve() {
    f[0] = f[1] = 1;
    for (int i = 2; i <= N; i++)
        f[i] = f[i - 1] + f[i - 2];
    int idx = 1;
    while (idx <= N) 
        if (K > f[N - idx]) {
            printf("%d %d ", idx + 1, idx);
            K -= f[N - idx];
            idx += 2;
        }
        else {
            printf("%d ", idx);
            idx++;
        }
    puts("");
}

int main() {
    load();
    solve();
    return 0;    
}