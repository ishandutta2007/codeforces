#include <cstdio>
#include <algorithm>
using namespace std;

int N, S;

void load() {
    scanf("%d%d", &N, &S);
}

int solve() {
    int sol = -1;
    while (N--) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (x < S || (x == S && !y))
            sol = max(sol, (100 - y) % 100);        
    }
    return sol;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}