#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)
#define rall(x) x.rbegin(), x.rend()

const int maxn = 1e5 + 42;

vector<int> g[maxn];
int used[maxn];
char win[maxn];

void dfs(int v) {
    if(used[v]) {
        return;
    }
    used[v] = 1;
    win[v] = 'B';
    for(auto u: g[v]) {
        dfs(u);
        if(win[u] == 'B') {
            win[v] = 'A';
        }
    }
}


signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = i; j >= 0; j -= a[i]) {
            if(a[j] > a[i]) {
                g[i].push_back(j);
            }
        }
        for(int j = i; j < n; j += a[i]) {
            if(a[j] > a[i]) {
                g[i].push_back(j);
            }
        }
    }
    for(int i = 0; i < n; i++) {
        dfs(i);
        cout << win[i];
    }
    return 0;
}


//