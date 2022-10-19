#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

const int MAXN = 100005;

int N, Q;
int a[MAXN], b[MAXN], l[MAXN];
vector <int> E[MAXN];
int cnt[MAXN];
ll sum;

void load() {
    scanf("%d", &N);
    for (int i = 1; i < N; i++) {
        scanf("%d%d%d", a + i, b + i, l + i);
        E[a[i]].push_back(b[i]);
        E[b[i]].push_back(a[i]);
    }
}

void dfs(int x, int p) {
    cnt[x] = 1;
    for (int i = 0; i < E[x].size(); i++) 
        if (E[x][i] != p) {
            dfs(E[x][i], x);
            cnt[x] += cnt[E[x][i]];
        }
}

void update(int x, int val) {
    sum += (ll)val * min(cnt[a[x]], cnt[b[x]]) * (N - min(cnt[a[x]], cnt[b[x]]));
}

void solve() {
    dfs(1, 0);
    for (int i = 1; i < N; i++) 
        update(i, l[i]);
    scanf("%d", &Q);
    while (Q--) {
        int r, w;
        scanf("%d%d", &r, &w);
        update(r, w - l[r]);
        l[r] = w;
        printf("%.10lf\n", 6 * (double)sum / ((ll)N * (ll)(N - 1)));
    }
}

int main() {
    load();
    solve();
    return 0;
}