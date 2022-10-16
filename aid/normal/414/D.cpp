#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100 * 1000 + 5;
int d[MAXN], c[MAXN];
long long s[MAXN];
vector<int> g[MAXN];

void dfs(int v, int p) {
    for(size_t i = 0; i < g[v].size(); i++)
        if(g[v][i] != p) {
            d[g[v][i]] = d[v] + 1;
            dfs(g[v][i], v);
        }
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, k, p;
    cin >> n >> k >> p;
    for(int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    dfs(0, -1);
    for(int i = 0; i < n; i++)
        c[d[i]]++;
    for(int i = 0; i < n; i++)
        s[i] = (long long)(n - i) * c[i];
    for(int i = n - 2; i >= 0; i--)
        s[i] += s[i + 1];
    for(int i = n - 2; i >= 0; i--)
        c[i] += c[i + 1];
    int ans = 0;
    for(int i = 1; i < n; i++) {
        int l = 0, r = i;
        while(l < r - 1) {
            int m = (l + r) / 2;
            if(s[m] - s[i] - (long long)(n - i) * (c[m] - c[i]) <= p)
                r = m;
            else
                l = m;
        }
        int sum = c[r] - c[i + 1],
            cost = s[r] - s[i] - (long long)(n - i) * (c[r] - c[i]);
        if(r > 1)
            sum += (p - cost) / (i - r + 1);
        sum = min(sum, k);
        ans = max(sum, ans);
    }
    cout << ans << '\n';
    return 0;
}