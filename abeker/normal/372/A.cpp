#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 500005;

int N;
int a[MAXN];

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", a + i);
}

bool check(int len) {
    for (int i = 0; i < len; i++)
        if (a[N + i - len] < 2 * a[i]) return false;
    return true;
}

int solve() {
    sort(a, a + N);
    int lo = 0, hi = N / 2;
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (check(mid)) lo = mid;
        else hi = mid - 1;
    }
    return N - lo;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}