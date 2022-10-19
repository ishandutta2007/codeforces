#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 2005;
const int MAXM = 5005;

int N;
int a[MAXN];
int cnt[MAXM];
ll sum[2 * MAXM];

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", a + i);
}

double solve() {
    sort(a, a + N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < i; j++)
            cnt[a[i] - a[j]]++;
    
    for (int i = 0; i < MAXM; i++)
        for (int j = 0; j < MAXM; j++)
            sum[i + j] += (ll)cnt[i] * cnt[j];
    
    for (int i = 1; i < 2 * MAXM; i++)
        sum[i] += sum[i - 1];
    
    ll sol = 0;
    for (int i = 1; i < MAXM; i++)
        sol += (ll)cnt[i] * sum[i - 1];
    
    double tot = N * (N - 1) / 2;
    return sol / (tot * tot * tot);
}

int main() {
    load();
    printf("%.10lf\n", solve());
    return 0;
}