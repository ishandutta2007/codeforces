#include <bits/stdc++.h>
using namespace std;

const int N = 200001;
int n, root = -1, add = 0, u1 = -1, u2 = -1, a[N];
vector<int> g[N];
vector<bool> used(N, false);
set<int> q;
bool flag = true;

void dfs0(int v, int pr) {
    used[v] = true;
    for(int to : g[v]) {
        if(!flag) break;
        if(!used[to])
            dfs0(to, v);
        else if(to != pr) {
            if(a[v] == to)
                a[v] = v, root = v;
            else
                a[to] = to, root = to;
            flag = false;
            u1 = v; u2 = to;
        }
    }
}

void dfs(int v, int pr) {
    used[v] = true;
    for(int to : g[v])
        if(!((v == u1 && to == u2) || (v == u2 && to == u1)))
            if(!used[to])
                dfs(to, v);
            else if(to != pr && v != to) {
                if(a[v] == to) q.insert(v);
                else q.insert(to);
            }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i]; a[i]--;
        if(a[i] == i)
            root = i;
        g[i].push_back(a[i]);
        g[a[i]].push_back(i);
    }
    if(root == -1) {
        for(int i = 0; i < n; i++)
            if(!used[i])
                dfs0(i, -1);
        used.assign(n, false);
        add = 1;
    }
    for(int i = 0; i < n; i++)
        if(a[i] == i && i != root)
            q.insert(i);
        else if(!used[i])
            dfs(i, -1);
    for(int v : q)
        a[v] = root;
    cout << (int)q.size() + add << endl;
    for(int i = 0; i < n; i++)
        cout << a[i] + 1 << ' ';
    return 0;
}