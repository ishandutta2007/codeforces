#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXM = 2000005;

int N;
bool cnt[MAXM];
int prev[MAXM];

void load() {
    scanf("%d", &N);
    while (N--) {
        int x; 
        scanf("%d", &x);
        cnt[x] = 1;
    }
}

int solve() {
    
    for (int i = 1; i < MAXM; i++)
        prev[i] = cnt[i - 1] ? i - 1 : prev[i - 1];
        
    int sol = 0;
    for (int i = 1; i < MAXM; i++) {
        if (!cnt[i]) continue;
        for (int j = 2 * i; j < MAXM; j += i)
            if (prev[j] >= i) 
                sol = max(sol, (i - (j - prev[j]) % i) % i);
    }
    
    return sol;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}