#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 300005;
const int MAXM = 1000005;

int N, K;
int a[MAXN];
int occ[2 * MAXM];

void load() {
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i++)
        scanf("%d", a + i);
}

int sum(int lo, int hi) {
    return occ[hi] - (lo ? occ[lo - 1] : 0);
}

int solve() {
    for (int i = 0; i < N; i++) 
        occ[a[i]]++;
    for (int i = 1; i < 2 * MAXM; i++)
        occ[i] += occ[i - 1];
        
    int mini = *min_element(a, a + N);
    if (K + 1 >= mini) return mini;
    
    int sol = K + 1;
    for (int i = K + 2; i <= mini; i++) {
        int cnt = 0;
        for (int j = i; j < MAXM; j += i) 
            cnt += sum(j, j + K);
        if (cnt == N) sol = i;
    }
    return sol;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}