#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 200005;

int N;
int a[MAXN];

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) { 
        scanf("%d", a + i);
        a[i] += i;
    }
}

void fail() {
    puts(":(");
    exit(0);
}

void solve() {
    sort(a, a + N);
    if (a[0] < 0) fail();
    for (int i = 1; i < N; i++) {
        a[i] -= i;
        if (a[i] < a[i - 1]) fail();
    }
    for (int i = 0; i < N; i++)
        printf("%d ", a[i]);
    puts("");
}

int main() {
    load();
    solve();
    return 0;
}