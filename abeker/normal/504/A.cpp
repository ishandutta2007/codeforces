#include <cstdio>
#include <cassert>
#include <set>
using namespace std;

const int MAXN = 1 << 16;

int N;
int deg[MAXN], sum[MAXN];
bool bio[MAXN];

struct cmp {
    bool operator()(const int &lhs, const int &rhs) const {
        if (deg[lhs] != deg[rhs]) return deg[lhs] < deg[rhs];
        return lhs < rhs;
    } 
};

set <int, cmp> S;

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) 
        scanf("%d%d", deg + i, sum + i);
}

void solve() {
    int sol = 0;
    for (int i = 0; i < N; i++) { 
        S.insert(i);
        sol += deg[i];
    }
    printf("%d\n", sol / 2);
    while (!S.empty()) {
        int x = *S.begin();
        S.erase(x);
        if (!deg[x]) continue;
        assert(deg[x] == 1);
        printf("%d %d\n", x, sum[x]);
        S.erase(sum[x]);
        deg[sum[x]]--;
        S.insert(sum[x]);
        sum[sum[x]] ^= x;
    }
}

int main() {
    load();
    solve();
    return 0;
}