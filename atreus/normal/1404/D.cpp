#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn = 1e6 + 10;

int h[maxn], last[maxn], cnt[maxn];
vector<int> g[maxn];
bool visited[maxn], root[maxn];

void dfs(int v){
    visited[v] = 1;
    cnt[v] = 1;
    for (auto u : g[v]){
        if (!visited[u]){
            h[u] = h[v]+1;
            dfs(u);
            cnt[v] += cnt[u];
        }
    }
}

int a[maxn];

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    if (n % 2 == 0){
        cout << "First" << endl;
        for (int i = 1; i <= 2*n; i++)
            cout << i%n + 1 << " ";
        cout << endl;
        int x;
        cin >> x;
        return 0;
    }
    cout << "Second" << endl;
    memset(last, -1, sizeof last);
    for (int i = 1; i <= 2*n; i++){
        if (i <= n)
            g[i].push_back(i+n), g[i+n].push_back(i);
        cin >> a[i];
        if (last[a[i]] == -1){
            last[a[i]] = i;
            continue;
        }
        g[i].push_back(last[a[i]]);
        g[last[a[i]]].push_back(i);
    }
    for (int i = 1; i <= 2*n; i++)
        if (!visited[i]){
            dfs(i);
            root[i] = 1;
        }
    int now = 0;
    for (int i = 1; i <= 2*n; i++)
        if (h[i] % 2 == 0)
            now = (now + i) % (2*n);
    if (now != 0){
        memset(visited, 0, sizeof visited);
        for (int i = 1; i <= 2*n; i++){
            if (root[i] and (cnt[i]/2) % 2 == 1){
                h[i] = 1;
                dfs(i);
                break;
            }
        }
    }
    for (int i = 1; i <= 2*n; i++)
        if (h[i] % 2 == 0)
            cout << i << " ";
    cout << endl;
    int x;
    cin >> x;
    return 0;
}