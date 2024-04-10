#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 205;
int a[MAXN], p[MAXN], used[MAXN];
vector<int> g[MAXN], g0[MAXN];
vector< vector<int> > ans;

bool prime(int x) {
    for(int i = 2; i * i <= x; i++)
        if(!(x % i))
            return false;
    return true;
}

bool dfs(int v, int col) {
    used[v] = col;
    for(size_t i = 0; i < g[v].size(); i++)
        if(p[g[v][i]] == -1) {
            p[g[v][i]] = v;
            return true;
        }
    for(size_t i = 0; i < g[v].size(); i++)
        if(used[p[g[v][i]]] != col && dfs(p[g[v][i]], col)) {
            p[g[v][i]] = v;
            return true;
        }
    return false;
}

bool dfs0(int v, int col) {
    used[v] = col;
    for(size_t i = 0; i < g0[v].size(); i++)
        if(p[g0[v][i]] == -1) {
            p[g0[v][i]] = v;
            return true;
        }
    for(size_t i = 0; i < g0[v].size(); i++)
        if(used[p[g0[v][i]]] != col && dfs0(p[g0[v][i]], col)) {
            p[g0[v][i]] = v;
            return true;
        }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        if(a[i] & 1)
            for(int j = 0; j < n; j++)
                if(!(a[j] & 1) && prime(a[i] + a[j]))
                    g[i].push_back(j);
    for(int i = 0; i < n; i++)
        used[i] = -1;
    for(int i = 0; i < n; i++)
        p[i] = -1;
    for(int i = 0; i < n; i++)
        if((a[i] & 1) && !dfs(i, i)) {
            cout << "Impossible\n";
            return 0;
        }
    for(int i = 0; i < n; i++)
        if(a[i] & 1)
            for(size_t j = 0; j < g[i].size(); j++)
                if(p[g[i][j]] != i)
                    g0[g[i][j]].push_back(i);
    for(int i = 0; i < n; i++)
        if(!(a[i] & 1) && !dfs0(i, i)) {
            cout << "Impossible\n";
            return 0;
        }
    for(int i = 0; i < n; i++)
        used[i] = 0;
    for(int i = 0; i < n; i++)
        if(!used[i]) {
            ans.push_back(vector<int>());
            int pos = i;
            while(!used[pos]) {
                ans.back().push_back(pos);
                used[pos] = true;
                pos = p[pos];
            }
        }
    cout << ans.size() << '\n';
    for(size_t i = 0; i < ans.size(); i++) {
        cout << ans[i].size() << ' ';
        for(size_t j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] + 1 << ' ';
        cout << '\n';
    }
    return 0;
}