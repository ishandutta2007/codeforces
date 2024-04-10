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

int n;
vector<int> vis[2];
vector<int> nxt[2];
vector<long long> p[2];
vector<long long> s[2];
vector<int> f[2];
vector<int> inf;

void dfs(int v, int t, int c) {
    vis[t][v] = c;
    s[t][v] = p[t][v];
    if (nxt[t][v] == 1) {
        f[t][v] = 1;
        return;
    }
    if (nxt[t][v] <= 0 || n < nxt[t][v])
        return;
    if (vis[1 - t][nxt[t][v]] == 0)
        dfs(nxt[t][v], 1 - t, c);
    else {
        if (vis[1 - t][nxt[t][v]] == c || inf[vis[1 - t][nxt[t][v]]] == 1)
            inf[c] = 1;
    }
    if (f[1 - t][nxt[t][v]] == 1)
        f[t][v] = 1;
    s[t][v] += s[1 - t][nxt[t][v]];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    vector<int> a(n + 1);
    
    for (int i = 0; i < 2; i++) {
        vis[i].resize(n + 1);
        nxt[i].resize(n + 1);
        p[i].resize(n + 1);
        s[i].resize(n + 1);
        f[i].resize(n + 1);
    }
    inf.resize(2 * n + 1);
    for (int i = 2; i <= n; i++) {
        cin >> a[i];
        nxt[0][i] = i + a[i];
        p[0][i] = a[i];
        nxt[1][i] = i - a[i];
        p[1][i] = a[i];
    }
    
    int c = 1;
    for (int j = 0; j < 2; j++) {
        for (int i = 2; i <= n; i++)
            if (vis[j][i] == 0)
                dfs(i, j, c++);
    }
    
    for (int i = 1; i < n; i++) {
        if (inf[vis[1][i + 1]] == 1) {
            cout << -1 << endl;
            continue;
        }
        if (f[1][i + 1] == 1) {
            cout << -1 << endl;
            continue;
        }
        if (f[1][i + 1] == 0) {
            cout << s[1][i + 1] + i << endl;
            continue;
        }
    }
            
}