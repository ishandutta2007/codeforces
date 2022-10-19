#include <cstdio>
using namespace std;

typedef long long ll;

const int MAXN = 100005;

int N, M;
ll a[MAXN];

void load() {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++)
        scanf("%I64d", a + i);
}

bool check(ll t) {
    ll sum = 0;
    int j = 0;
    for (int i = 0; i < M; i++) {
        for (; j <= N; j++)
            if (a[j + 1] > t + sum) break;
        sum += t - (ll)j - 1;
    }
    return j > N;
}

ll solve() {
    while (!a[N]) N--;
    for (int i = 1; i <= N; i++)
        a[i] += a[i - 1] + 1;
    ll lo = 0, hi = (ll)1e15;
    while (lo < hi) {
        ll mid = (lo + hi) / 2;
        if (check(mid)) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

int main() {
    load();
    printf("%I64d\n", solve());
    return 0;
}