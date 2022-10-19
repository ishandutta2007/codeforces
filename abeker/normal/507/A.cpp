#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 105;

int N, K;
int a[MAXN], idx[MAXN];

void load() {
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i++) {
        scanf("%d", a + i);
        idx[i] = i;
    }
}

bool cmp(const int &l, const int &r) {
    return a[l] < a[r];
}

void solve() {
    sort(idx, idx + N, cmp);
    int sum = 0, sol = N;
    for (int i = 0; i < N; i++) {
        sum += a[idx[i]];
        if (sum > K) { sol = i; break; }
    }
    printf("%d\n", sol);
    for (int i = 0; i < sol; i++) 
        printf("%d ", ++idx[i]);
    puts("");
}

int main() {
    load();
    solve();
    return 0;
}