#include <cstdio>
#include <algorithm>
using namespace std;

int hpy, atky, defy;
int hpm, atkm, defm;
int h, a, d;

void load() {
    scanf("%d%d%d", &hpy, &atky, &defy);
    scanf("%d%d%d", &hpm, &atkm, &defm);
    scanf("%d%d%d", &h, &a, &d);
}

int solve() {
    int sol = (int)2e9;
    for (int i = 1; i <= 100; i++) {
        if (atky - defm > i) continue;
        int t = (hpm + i - 1) / i;
        for (int j = 0; j < 10000; j++) {
            int c = hpy + j;
            int e = max(atkm - (c - 1) / t - defy, 0);
            sol = min(sol, (i - atky + defm) * a + j * h + e * d);
        }    
    }
    return sol;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}