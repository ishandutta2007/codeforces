#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100005;

int N;
int a[MAXN];
int pref[MAXN], suff[MAXN];

void load() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", a + i);
}

int solve() {
    for (int i = 1; i <= N; i++) 
        pref[i] = min(pref[i - 1], a[i] - i);
        
    suff[N + 1] = N + 1;
    for (int i = N; i; i--)
        suff[i] = min(suff[i + 1], a[i] + i);
    
    int sol = 0;
    for (int i = 1; i <= N; i++) 
        sol = max(sol, min(pref[i] + i, suff[i + 1] - i));
    return sol;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}