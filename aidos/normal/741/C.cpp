#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 100;
vector<int> g[maxn];
int n;
int a[maxn];
int b[maxn];
int u[maxn];
void dfs(int v, int col) {
    u[v] = col;
    for(int to: g[v]) {
        if(!u[to]) {
            dfs(to, 3 - col);
        }
    }
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) {
        g[i*2-1].push_back(2 * i);
        g[i*2].push_back(2 * i - 1);
    }
    for(int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }
    for(int i = 1; i <= 2 * n; i++) {
        if(u[i] == 0) {
            dfs(i, 1);
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << u[a[i]] << " " << u[b[i]] << "\n";
    }
}