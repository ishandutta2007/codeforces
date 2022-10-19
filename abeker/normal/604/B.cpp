#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 100005;

int N, K;
int a[MAXN];
bool bio[MAXN];

void load() {
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i++)
        scanf("%d", a + i);
}

bool check(int s) {
    memset(bio, false, sizeof bio);
    int j = N, cnt = 0;
    for (int i = 0; i < N; i++) {
        if (bio[i]) continue;
        for (j--; j > i && a[i] + a[j] > s; j--);
        if (j > i) bio[j] = true;
        cnt++;
    }
    return cnt <= K;
}

int solve() {
    int lo = a[N - 1], hi = 2000000;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}