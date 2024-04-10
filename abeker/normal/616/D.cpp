#include <cstdio>
using namespace std;

const int MAXN = 500005;
const int MAXM = 1000005;

int N, K;
int a[MAXN];
int cnt[MAXM];

void load() {
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i++)
        scanf("%d", a + i);
}

void solve() {
    int j = 0, d = 0;
    int maks = 0, l = 0, r = 0;
    for (int i = 0; i < N; i++) {
        for (; j < N; j++) {
            if (!cnt[a[j]]) d++;
            cnt[a[j]]++;
            if (d > K) break;
        }
        cnt[a[j]]--;
        d--;
        int tmp = j - i;
        if (tmp > maks) {
            maks = tmp;
            l = i;
            r = j - 1;
        }
        cnt[a[i]]--;
        if (!cnt[a[i]]) d--;
    }
    printf("%d %d\n", ++l, ++r);
}

int main() {
    load();
    solve();
    return 0;
}