#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100005;

int occ[MAXN];

int main() {
    int N;
    scanf("%d", &N);
    int sol = 0, last = 0, dp = 0;
    for (int i = 1; i <= N; i++) {
        int x; 
        scanf("%d", &x);
        x++;
        if (x < last)
            dp = i - max(occ[x - 1], occ[x + 2]);
        else if (x > last)
            dp = i - max(occ[x - 2], occ[x + 1]);
        else
            dp++;
        sol = max(sol, dp);
        last = x;
        occ[x] = i;
    }
    printf("%d\n", sol);
    return 0;
}