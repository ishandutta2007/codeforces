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

const int maxN = 4018;
const int maxK = 81;
const int mod = 998244353;

int n, m, k, i, j, x, y;
vector<int> list[maxN];
ll ans[maxN], ans2[maxN];

int down[maxN];
bool dead[maxN];
vector<int> act;

ll dp[maxK][maxN], dp2[maxK][maxN];
ll sol, comb[maxK][maxK];

void make_clean(vector<int>& aux) {
    int i;
    for (i = 0; i < aux.size(); i++) {
        if (dead[aux[i]]) {
            aux[i] = aux.back();
            aux.pop_back();
            i--;
            continue;
        }
    }
}

void dfs(int node, int root) {
    make_clean(list[node]);
    down[node] = 1;
    act.pb(node);

    for (auto to : list[node])
        if (to != root)
            dfs(to, node), down[node] += down[to];
}

int dfs2(int node, int root, int target) {
    bool ok = (target - down[node]) <= target / 2;

    for (auto to : list[node]) {
        if (to == root) continue;
        int ans = dfs2(to, node, target);
        if (ans != 0) return ans;
        ok &= (down[to] <= target / 2);
    }

    if (ok) return node;
    return 0;
}

void add(ll &a, ll b) {
    a += b;
    if (a >= mod) a -= mod;
}

void solve(int R) {
    int i, j;

    act.clear();
    dfs(R, 0);
    R = dfs2(R, 0, down[R]);

    for (i = 0; i <= k; i++)
        for (auto e : act) 
            dp[i][e] = dp2[i][e] = 0;

    dp[0][R] = dp2[0][R] = 1;
    for (i = 1; i <= k; i++) {
        for (auto e : act) {
            for (auto to : list[e]) {
                add(dp[i][to], dp[i - 1][e]);
                if (to != R) add(dp2[i][to], dp2[i - 1][e]);
            }
        }
    }

    for (i = 1; i <= k; i++) {
        for (j = 1; j <= k; j++) {
            for (auto e : act) {
                if (e == R) {
                    if (j == 1) add(ans[i], dp[i][R]);
                } else {
                    add(ans[i + j], (dp[i][e] * dp2[j][e]) % mod);
              }
            }
        }
    }
    
    dead[R] = true;
    for (auto to : list[R])
        solve(to);
        
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d%d", &n, &m, &k);
    
    for (i = 1; i < n; i++) {
        scanf("%d%d", &x, &y);
        list[x].pb(y);
        list[y].pb(x);
    }
    solve(1);

    for (i = 1; i <= max(n, k); i++) {
        ans2[i] = ans[i];
        ans[i] = 0;
        list[i].clear();
        dead[i] = 0;
    }
    for (i = 1; i < m; i++) {
        scanf("%d%d", &x, &y);
        list[x].pb(y);
        list[y].pb(x);
    }
    solve(1);

    swap(n, m);
    ans[0] = n;
    ans2[0] = m;

    /*for (i = 0; i <= k; i++) cerr << ans[i] << ' ';
    cerr << '\n';
    for (i = 0; i <= k; i++) cerr << ans2[i] << ' ';
    cerr << '\n';
    */

    for (i = 0; i <= k; i++) {
        comb[i][0] = 1;
        for (j = 1; j <= i; j++)
            comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % mod;
    }

    for (i = 0; i <= k; i++) {
        j = k - i;
        add(sol, (((ans[i] * ans2[j]) % mod) * comb[i + j][j]) % mod);
    }

    printf("%lld", sol);


    return 0;
}