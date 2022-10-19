#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 200005;

struct fenwick {
    int f[MAXN], cnt;
    fenwick() {
        cnt = 0;
        memset(f, 0, sizeof f);
    }
    inline void update(int x) {
        for (; x < MAXN; x += x & -x) 
            f[x]++;
        cnt++;
    }
    inline int get(int x) {
        int ret = 0;
        for (; x; x -= x & -x) 
            ret += f[x];
        return ret;
    }
};
            
int N, M;
int a[MAXN], p[MAXN];
vector <int> v[MAXN], e[MAXN];
int l[MAXN], r[MAXN], sol[MAXN];
fenwick F;

void load() {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++) 
        scanf("%d", a + i);
    for (int i = 0; i < M; i++) {
        scanf("%d%d", l + i, r + i);
        e[r[i]].push_back(i);
    }
}

void solve() {
    for (int i = 1; i <= N; i++) 
        p[a[i]] = i;
    for (int i = 1; i <= N; i++) 
        for (int j = i; j <= N; j += i) 
            v[max(p[i], p[j])].push_back(min(p[i], p[j]));
    for (int i = 1; i <= N; i++) {
        for (vector <int> :: iterator it = v[i].begin(); it != v[i].end(); it++) 
            F.update(*it);
        for (vector <int> :: iterator it = e[i].begin(); it != e[i].end(); it++)
            sol[*it] = F.cnt - F.get(l[*it] - 1);
    }
    for (int i = 0; i < M; i++) 
        printf("%d\n", sol[i]);
}

int main() {
    load();
    solve();
    return 0;
}