#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <fstream>

#define F first
#define S second
#define PB push_back
using namespace std;

const int maxn = 1e5 + 100;
bool mark[maxn];
int h[maxn];
vector <int> v[maxn];
int ans;

void dfs(int u, int x, int dad){
    mark[u] = true;
    h[u] = x;
//    cout << u << " " << x << " " << dad << endl;
    for (int i = 0; i < v[u].size(); i++){
//        cout << v[u][i] << " - ";
        if (!mark[v[u][i]])
            dfs(v[u][i], x + 1, u);
        else
            if (v[u][i] != dad)
                if (h[u] % 2 == h[v[u][i]] % 2)
                    ans = -1;


    }
}

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int u, w;
        cin >> u >> w;
        v[u].push_back(w);
        v[w].push_back(u);
    }
    for (int i = 1; i <= n; i++){
        if (!mark[i])
          dfs(i, 0, -1);
    }
    vector <int> a1, a2;
    if (ans == -1)
        return cout << ans, 0;
    for (int i = 1; i <= n; i++){
//        cout << h[i] << " ";
        if (h[i] % 2 == 0)
            a1.push_back(i);
        else
            a2.push_back(i);
    }
    cout << a1.size() << endl;
    for (int i = 0; i < a1.size(); i++)
        cout << a1[i] << " ";
    cout << endl << a2.size() << endl;
    for (int i = 0; i < a2.size(); i++)
        cout << a2[i] << " ";
}