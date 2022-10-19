#include <cstdio>
using namespace std;

const int MAXN = 5005;

int N;
int a[MAXN];

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) 
        scanf("%d", a + i);
}

int solve(int lo, int hi) {
    if (lo == hi) return 0;
    if (lo == hi - 1) return a[lo] ? 1 : 0;
    int m = a[lo];
    for (int i = lo; i < hi; i++) 
        if (a[i] < m) m = a[i];
    int sum = m, last = lo;
    for (int i = lo; i < hi && sum < hi - lo; i++) {
        a[i] -= m; 
        if (!a[i]) {
            sum += solve(last, i);
            last = i + 1;
        }
    }
    if (sum < hi - lo) sum += solve(last, hi);
    if (sum > hi - lo) sum = hi - lo;
    return sum; 
}

int main() {
    load();
    printf("%d\n", solve(0, N));
    return 0;
}