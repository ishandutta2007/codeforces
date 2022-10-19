#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

const int MAXN = 500005;
const int INF = 0x3f3f3f3f;

struct fenwick {
    int f[MAXN];
    
    fenwick() {
        memset(f, INF, sizeof f);
    }
    
    void update(int x, int val) {
        for (; x < MAXN; x += x & -x)
            f[x] = min(f[x], val);
    }
    
    int get(int x) {
        int ret = INF;
        for (; x; x -= x & -x)
            ret = min(ret, f[x]);
        return ret;
    }
};

int N, M;
int a[MAXN];
int l[MAXN], r[MAXN];
int sol[MAXN];
vector <int> Q[MAXN];
map <int, int> last;
fenwick F;

void load() {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++)
        scanf("%d", a + i); 
}

void solve() {
    for (int i = 0; i < M; i++) {
        scanf("%d%d", l + i, r + i);
        Q[l[i]].push_back(i);
    }
    
    for (int i = N; i; i--) {
        int pos = last[a[i]];
        last[a[i]] = i;
        if (pos) F.update(pos, pos - i);
        for (int j = 0; j < Q[i].size(); j++)
            sol[Q[i][j]] = F.get(r[Q[i][j]]);
    }
    
    for (int i = 0; i < M; i++)
        printf("%d\n", sol[i] == INF ? -1 : sol[i]);
}

int main() {
    load();
    solve();
    return 0;
}