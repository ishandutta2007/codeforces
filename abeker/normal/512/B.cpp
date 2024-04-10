#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 305;
const int INF = 0x3f3f3f3f;

int N;
int l[MAXN], c[MAXN];
int dp[1 << 8];
vector <int> V;

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) 
        scanf("%d", l + i);
    for (int i = 0; i < N; i++)
        scanf("%d", c + i);
}

void factor(int x) {
    V.clear();
    for (int i = 2; i * i <= x; i++) {
        if (x % i) continue;
        while (!(x % i)) x /= i;
        V.push_back(i);
    }
    if (x > 1) V.push_back(x);
}

int rec(int x, int mask) {
    int &ref = dp[mask];
    if (ref != INF) return ref;
    for (int i = 0; i < x; i++) {
        int nmask = (1 << (int)V.size()) - 1;
        for (int j = 0; j < V.size(); j++) 
            if (l[i] % V[j]) nmask ^= 1 << j;
        nmask &= mask;
        if (nmask == mask) continue;
        ref = min(ref, rec(x, nmask) + c[i]);
    }
    return ref;       
}

int solve() {
    int sol = INF;    
    for (int i = 0; i < N; i++) {
        if (l[i] == 1) {
            sol = min(sol, c[i]);
            continue;
        }
        factor(l[i]); 
        memset(dp, INF, sizeof dp);
        dp[0] = 0;
        sol = min(sol, c[i] + rec(i, (1 << (int)V.size()) - 1));    
        //printf("%d\n", rec(i, (1 << (int)V.size()) - 1));
    }
    if (sol == INF) sol = -1;
    return sol;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}