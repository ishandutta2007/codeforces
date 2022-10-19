#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 100005;
const int INF = 0x3f3f3f3f;

int N, D;
pii p[MAXN];
ll sum[MAXN];

void load() {
    scanf("%d%d", &N, &D);
    for (int i = 1; i <= N; i++)
        scanf("%d%d", &p[i].first, &p[i].second);
}

ll solve() {
    sort(p + 1, p + N + 1);
    for (int i = 1; i <= N; i++)
        sum[i] = sum[i - 1] + (ll)p[i].second;
    
    ll sol = 0;
    for (int i = 1; i <= N; i++) {
        int pos = upper_bound(p + 1, p + N + 1, pii(p[i].first + D - 1, INF)) - p - 1;
        sol = max(sol, sum[pos] - sum[i - 1]); 
    }
    return sol;
}

int main() {
    load();
    printf("%I64d\n", solve());
    return 0;
}