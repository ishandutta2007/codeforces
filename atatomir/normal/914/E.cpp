#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 200011
#define sigma 20

//! atentie la LONG LONG

int n, i, x, y;
char s[maxN];
vector<int> list[maxN];
bool dead[maxN];

ll down[maxN];
ll sol[maxN], added, msk;
int M[1 << 22];

void refr(vector<int>& data) {
    int i;

    for (i = 0; i < data.size(); i++) {
        if (!dead[data[i]]) continue;
        data[i] = data.back();
        data.pop_back();
        i--;
        continue;
    }
}

void dfs(int node, int root) {
    down[node] = 1;

    refr(list[node]);
    for (auto to : list[node]) {
        if (to == root) continue;
        dfs(to, node);
        down[node] += down[to];
    }
}

int dfs2(int node, int root, int target) {
    bool ok = (target - down[node]) <= target / 2;

    for (auto to : list[node]) {
        if (to == root) continue;
        int ans = dfs2(to, node, target);
        if (ans) return ans;
        ok &= (down[to] <= (target / 2));
    }

    if (ok) return node;
    return 0;
}

void dfs_add(int node, int root, int act) {
    act ^= (1 << (s[node] - 'a'));
    M[act]++;

    for (auto to : list[node])
        if (to != root)
            dfs_add(to, node, act);
}

void dfs_rm(int node, int root, int act) {
    act ^= (1 << (s[node] - 'a'));
    M[act]--;

    for (auto to : list[node])
        if (to != root)
            dfs_rm(to, node, act);
}

void dfs_sol(int node, int root, int act) {
    act ^= (1 << (s[node] - 'a'));

    int aux = act ^ msk;
    if ( (aux & (aux - 1)) == 0 ) added++;

    down[node] = 1LL * M[act];
    for (int i = 0; i < sigma; i++)
        down[node] += 1LL * M[act ^ (1 << i)];

    for (auto to : list[node]) {
        if (to == root) continue;
        dfs_sol(to, node, act);

        down[node] += down[to];
    }

    sol[node] += down[node];
}

void solve(int R) {

    dfs(R, 0);
    R = dfs2(R, 0, down[R]);

    msk = (1 << (s[R] - 'a'));
    M[msk] = 1;
    added = 0;
    sol[R]++;

    for (auto to : list[R])
        dfs_add(to, R, msk);

    for (auto to : list[R]) {
        dfs_rm(to, R, msk);
        dfs_sol(to, R, 0);
        added += down[to];
        dfs_add(to, R, msk);
    }

    for (auto to : list[R])
        dfs_rm(to, R, msk);

    M[msk] = 0;

    sol[R] += added / 2;

    dead[R] = true;
    for (auto to : list[R])
        solve(to);

}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i < n; i++) {
        scanf("%d%d\n", &x, &y);
        list[x].pb(y);
        list[y].pb(x);
    }
    scanf("%s", s + 1);

    /*for (i = n + 1; i <= 200000; i++) {
        x = i;
        y = (rand() % (i - 1)) + 1;
        list[x].pb(y);
        list[y].pb(x);
        s[i] = 'a' + (rand() % sigma);
    }
    n = 200000;*/

    solve(1);
    for (i = 1; i <= n; i++) printf("%lld ", sol[i]);


    return 0;
}