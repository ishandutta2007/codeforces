#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 200005;

int N, K;
int a[MAXN];
vector <int> E[MAXN];
vector <int> V;
int subtree[MAXN];
bool ok[MAXN];
int cnt_ok[MAXN];
bool entire[MAXN];
int dp[MAXN];
vector <int> up[MAXN];

void load() {
    scanf("%d%d", &N, &K);
    for (int i = 1; i <= N; i++)
        scanf("%d", a + i);
    for (int i = 1; i < N; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
}

void dfs(int x, int p) {
    subtree[x] = 1;
    cnt_ok[x] = ok[x];
    dp[x] = 0;
    int maks = 0;
    for (int i = 0; i < E[x].size(); i++) {
        int nxt = E[x][i];
        if (nxt == p) continue;
        dfs(nxt, x);
        subtree[x] += subtree[nxt];
        cnt_ok[x] += cnt_ok[nxt];
        if (entire[nxt]) dp[x] += subtree[nxt];
        else maks = max(maks, dp[nxt]);
    }
    dp[x] += maks + 1;
    if (!ok[x]) dp[x] = 0;
    entire[x] = subtree[x] == cnt_ok[x];
}

bool check_up(int x) {
    return cnt_ok[1] - cnt_ok[x] == subtree[1] - subtree[x];
}

bool go(int x, int p, int id) {
    int sum = 0;
    vector <int> tmp;
    int mx1 = 0, mx2 = 0;
    for (int i = 0; i < E[x].size(); i++) {
        int nxt = E[x][i];
        if (nxt == p) {
            tmp.push_back(0);
            continue;
        }
        int curr = 0;
        if (entire[nxt]) sum += subtree[nxt];
        else curr = dp[nxt];
        tmp.push_back(curr);
        if (curr >= mx1) {
            mx2 = mx1;
            mx1 = curr;
        }
        else if (curr > mx2) 
            mx2 = curr;
    }
    
    for (int i = 0; i < E[x].size(); i++) {
        int nxt = E[x][i];
        if (nxt == p) {
            up[x].push_back(0);
            continue;
        }
        int tot = sum;
        if (entire[nxt]) tot -= subtree[nxt];
        else if (tmp[i] == mx1) tmp[i] = mx2;
        if (check_up(x)) tot += subtree[1] - subtree[x];
        else tmp[i] = max(tmp[i], up[p][id]);
        tot += tmp[i] + 1;
        if (!ok[x]) tot = 0;
        up[x].push_back(tot);
        if (go(nxt, x, i)) return true;
    }
    
    if (check_up(x)) sum += subtree[1] - subtree[x];
    else mx1 = max(mx1, up[p][id]);
    int sol = sum + mx1 + 1;
    if (!ok[x]) sol = 0;
    
    return sol >= K;    
}

bool check(int val) {
    for (int i = 1; i <= N; i++) {
        ok[i] = a[i] >= val;
        up[i].clear();
    }
    
    dfs(1, 0);
    
    return go(1, 0, 0);
}

int solve() {
    for (int i = 1; i <= N; i++)
        V.push_back(a[i]);
    sort(V.begin(), V.end());
    
    int lo = 0, hi = N;
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (check(V[mid])) lo = mid;
        else hi = mid - 1;
    }
    
    return V[lo];
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}