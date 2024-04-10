#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 100005;
const int MOD = 1000000007;

const char c[] = "ACGT";

int N;
char s[MAXN];
int cnt[500];

inline int mul(int x, int y) {
    return (ll)x * y % MOD;
}

void load() {
    scanf("%d%s", &N, s);
}

int solve() {
    for (int i = 0; i < N; i++)
        cnt[s[i]]++;
    int sol = 1, occ = count(cnt, cnt + 500, *max_element(cnt, cnt + 500));
    while (N--) sol = mul(sol, occ);
    return sol;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}