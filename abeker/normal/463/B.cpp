#include <cstdio>
#include <algorithm>
using namespace std;

int N;

int solve() {
    int sol = 0;
    scanf("%d", &N);
    while (N--) {
        int h; scanf("%d", &h);
        sol = max(sol, h);
    }
    return sol;    
}

int main() {
    printf("%d\n", solve());
    return 0;
}