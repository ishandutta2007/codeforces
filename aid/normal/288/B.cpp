#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXK = 10, MOD = 1000 * 1000 * 1000 + 7;
int p[MAXK];
char used[MAXK];
vector<int> g[MAXK];

void dfs(int v) {
    used[v] = true;
    for(size_t i = 0; i < g[v].size(); i++)
        if(!used[g[v][i]])
            dfs(g[v][i]);
}

bool check(int k) {
    for(int i = 0; i < k; i++)
        g[i].clear();
    for(int i = 0; i < k; i++)
        g[p[i]].push_back(i);
    for(int i = 0; i < k; i++)
        used[i] = false;
    dfs(0);
    for(int i = 0; i < k; i++)
        if(!used[i])
            return false;
    for(int i = 0; i < k; i++)
        used[i] = false;
    int v = 0;
    while(!used[v]) {
        used[v] = true;
        v = p[v];
    }
    return v == 0;
}

int brute(int pos, int k) {
    if(pos == k)
        return check(k);
    int res = 0;
    for(int i = 0; i < k; i++) {
        if(pos && i == pos)
            continue;
        p[pos] = i;
        res += brute(pos + 1, k);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    int f = 1;
    for(int i = 0; i < n - k; i++)
        f = ((long long)f * (n - k)) % MOD;
    cout << ((long long)brute(0, k) * f) % MOD << '\n';
    return 0;
}