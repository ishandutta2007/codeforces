#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 500005;
const int INF = (int)1e9;

int N, K;
int a[MAXN];
    
void load() {
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i++)
        scanf("%d", a + i);
}

int solve() {
    ll tot = 0;
    for (int i = 0; i < N; i++)
        tot += a[i];
        
    int lo = 0, hi = (int)(tot / N);
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        ll sum = 0;
        for (int i = 0; i < N; i++)
            sum += max(mid - a[i], 0);
        if (sum <= K) lo = mid;
        else hi = mid - 1;
    }
    
    int old = lo;
    
    lo = (int)((tot - 1) / N) + 1, hi = INF;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        ll sum = 0;
        for (int i = 0; i < N; i++)
            sum += max(a[i] - mid, 0);
        if (sum <= K) hi = mid;
        else lo = mid + 1;
    }
    
    return max(lo - old, 0);
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}