#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define M 100100

int n;
bool u[M], a[M], b[M];
vector<int> g[M], ans;

void read(void){
    cin >> n;
    for (int i = 0, x, y; i < n - 1; ++i){
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> b[i];
}

void dfs(int v, bool d, bool x0, bool x1){
    u[v] = 1;

    if ((d && x1) || (!d && x0))
        a[v] = !a[v];

    bool y1 = x1;
    bool y0 = x0;

    if (a[v] != b[v]){
        if (d)
            y1 = !y1;
        else
            y0 = !y0;
        ans.push_back(v);
    }

    
    for (auto &to : g[v])
    if (!u[to])
        dfs(to, !d, y0, y1);
}

int main(){
#ifdef GORILLA
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
#endif

    read();
    dfs(1, 0, 0, 0);
    cout << ans.size() << "\n";

    for (auto &x : ans)
        cout << x << "\n";
    

    return 0;
}