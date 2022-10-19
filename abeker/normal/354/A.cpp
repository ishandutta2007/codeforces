#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;

const int MAXN = 100005;

int N;
int L, R, A, B;
int w[MAXN];
int pref[MAXN], suff[MAXN];

void load() {
    scanf("%d%d%d%d%d", &N, &L, &R, &A, &B);    
    for (int i = 1; i <= N; i++)
        scanf("%d", w + i);
}

int solve() {
    for (int i = 1; i <= N; i++)
        pref[i] = pref[i - 1] + w[i];
    
    for (int i = N; i; i--)
        suff[i] = suff[i + 1] + w[i];
    
    int sol = INT_MAX;
    for (int i = 0; i <= N; i++)
        sol = min(sol, pref[i] * L + suff[i + 1] * R + (2 * i > N ? (2 * i - N - 1) * A : max(0, N - 2 * i - 1) * B));
    return sol;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}