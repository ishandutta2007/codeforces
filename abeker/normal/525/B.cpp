#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 200005;

int N, M;
char s[MAXN];
int cnt[MAXN];

void load() {
    scanf("%s", s + 1);
}

void solve() {
    scanf("%d", &M);
    while (M--) {
        int pos;
        scanf("%d", &pos);
        cnt[pos]++;
    }
    N = strlen(s + 1);
    for (int i = 1; 2 * i <= N; i++) {
        cnt[i] += cnt[i - 1];
        if (cnt[i] & 1) swap(s[i], s[N + 1 - i]);
    }
    puts(s + 1);
}

int main() {
    load();
    solve();
    return 0;
}