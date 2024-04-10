#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100 * 1000 + 5;
char b[MAXN], bb[MAXN], c[MAXN];
vector<int> g[MAXN];

void dfs(int v, int p) {
    int children = 0, cntbb = 0, cnt = 0;
    bool bad = false;
    for(size_t i = 0; i < g[v].size(); i++)
        if(g[v][i] != p) {
            children++;
            dfs(g[v][i], v);
            if(!b[g[v][i]] && !bb[g[v][i]]) {
                if(!c[g[v][i]])
                    bad = true;
                cnt++;
            }
            if(bb[g[v][i]])
                cntbb++;
        }
    if(bad)
        return;
    if(children <= 1 && cnt == 0 && cntbb == 0) {
        b[v] = true;
        c[v] = true;
        return;
    }
    if(children == 2 && cnt == 0 && cntbb == 0) {
        bb[v] = true;
        c[v] = true;
        return;
    }
    if(cnt <= 1 || (cnt == 2 && p == -1))
        c[v] = true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    int root = -1;
    for(int i = 0; i < n; i++)
        if(g[i].size() > 2) {
            root = i;
            break;
        }
    if(root == -1) {
        cout << "Yes\n";
        return 0;
    }
    dfs(root, -1);
    if(c[root])
        cout << "Yes\n";
    else if(g[root].size() > 3)
        cout << "No\n";
    else {
        int v = -1;
        for(size_t i = 0; i < g[root].size(); i++)
            if(!b[g[root][i]]) {
                if(v == -1)
                    v = g[root][i];
                else
                    v = -2;
            }
        if(v < 0) {
            cout << "No\n";
            return 0;
        }
        for(int i = 0; i < n; i++) {
            b[i] = false;
            bb[i] = false;
            c[i] = false;
        }
        root = v;
        dfs(root, -1);
        if(c[root])
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}