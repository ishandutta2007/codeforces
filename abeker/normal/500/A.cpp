#include <cstdio>
using namespace std;

const int MAXN = 30005;

int N, T;
int a[MAXN];

void load() {
    scanf("%d%d", &N, &T);
    for (int i = 1; i < N; i++) 
        scanf("%d", a + i);
}

bool solve() {
    a[N] = 1;
    for (int x = 1; x <= N; x += a[x])
        if (x == T) return true;
    return false;
}

int main() {
    load();
    puts(solve() ? "YES" : "NO");
    return 0;
}