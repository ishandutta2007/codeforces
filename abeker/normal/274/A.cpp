#include <cstdio>
#include <set>
using namespace std;

const int INF = 0x3f3f3f3f;

int N, K;
set <int> S;

int main() {
    scanf("%d%d", &N, &K);
    if (K == 1) {
        printf("%d\n", N);
        return 0;
    }
    while (N--) {
        int x;
        scanf("%d", &x);
        S.insert(x);
    }
    int sol = 0;
    for (; !S.empty(); sol++) {
        int x = *S.begin();
        S.erase(x);
        if (x <= INF / K && S.count(K * x)) 
            S.erase(K * x);
    }
    printf("%d\n", sol);
    return 0;
}