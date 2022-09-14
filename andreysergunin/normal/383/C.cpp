#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <ctime>

using namespace std;

vector< vector<int> > edge;
vector<int> l[2], r[2];
vector<int> tin[2];
vector<int> par, pos;

class BinaryIndexedTree {
public:
    BinaryIndexedTree() {}
    BinaryIndexedTree(int n) {
        n_ = n;
        arr_.resize(n_);
    }
    
    void update(int x, int val) {
        if (x < 0 || x >= n_)
            return;
        for (int i = x ; i < n_ ; i = i | (i + 1))
            arr_[i] += val;
    }
    
    int getSum(int x) {
        if (x < 0 || x >= n_)
            return 0;
        int ans = 0;
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
            ans += arr_[i];
        return ans;
    }
private:
    int n_;
    vector<int> arr_;
};

void dfs(int v, int p, int e) {
    tin[e].push_back(v);
    par[v] = e;
    pos[v] = (int)tin[e].size() - 1;
    l[e][v] = (int)tin[e].size() - 1;
    l[1 - e][v] = (int)tin[1 - e].size();
    for (int i = 0; i < (int)edge[v].size(); i++)
        if (edge[v][i] != p)
            dfs(edge[v][i], v, 1 - e);
    r[e][v] = (int)tin[e].size();
    r[1 - e][v] = (int)tin[1 - e].size();
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    edge.resize(n);
    par.resize(n);
    pos.resize(n);
    for (int i = 0; i < 2; i++) {
        l[i].resize(n);
        r[i].resize(n);
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(0, -1, 0);
    BinaryIndexedTree tree[2];
    for (int i = 0; i < 2; i++)
        tree[i] = BinaryIndexedTree((int)tin[i].size());
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < (int)tin[i].size(); j++)
            tree[i].update(j, a[tin[i][j]] - (j == 0 ? 0 : a[tin[i][j - 1]]));
    }
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, val;
            cin >> x >> val;
            x--;
            tree[par[x]].update(l[par[x]][x], val);
            tree[par[x]].update(r[par[x]][x], -val);
            tree[1 - par[x]].update(l[1 - par[x]][x], -val);
            tree[1 - par[x]].update(r[1 - par[x]][x], val);
        }
        else {
            int x;
            cin >> x;
            x--;
            printf("%d\n", tree[par[x]].getSum(pos[x]));
        }
    }
    return 0;
}