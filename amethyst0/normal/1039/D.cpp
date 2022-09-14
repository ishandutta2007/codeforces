#include <cstdio>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <bitset>
#include <time.h>
#define ll long long
#define mp make_pair
#define pii pair <int, int>

using namespace std;

const int maxn = (int)1e5 + 10;

int p[maxn];
vector <int> ed[maxn];
int g[maxn];

void dfs(int x, int pr, int d=0) {
    p[x] = pr;
    g[x] = d;
    
    for (int i = 0; i < (int)ed[x].size(); i++) {
        int u = ed[x][i];
        
        if (u == pr) {
            swap(ed[x][i], ed[x].back());
            ed[x].pop_back();
            i--;
        } else {
            dfs(u, x, d + 1);
        }
    }
}

int ans[maxn];

int sq = 77;

int n;

vector <pii> ver;
/*bool used[maxn];

int get_down(int v) {
    queue <int> q;
    
    for (int i = 0; i < (int)ed[v].size(); i++) {
        int u = ed[v][i];
        if (!used[u]) {
            q.push(u);
        }
    }
    
    int res = 0;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        res = max(res, g[u] - g[v]);
        used[u] = true;
        
        for (int i = 0; i < (int)ed[u].size(); i++) {
            int to = ed[u][i];
            
            if (!used[to]) {
                q.push(to);
            }
        }
    }
    
    return res;
}

int get_up(int v, int cn) {
    while (v != -1) {
        used[v] = true;
        int d = get_down(v);
        
        if (d >= cn) {
            return 1;
        }
        
        v = p[v];
        cn--;
    }
    
    return 0;
}*/

pii lens[maxn];

int get_ans(int k) {
    int res = 0;
    
    for (int i = 0; i < (int)ver.size(); i++) {
        int v = ver[i].second;
        
        pii best = mp(0, 0);
        
        for (int j = 0; j < (int)ed[v].size(); j++) {
            int u = ed[v][j];
            int cur = lens[u].first + 1;
            if (cur > best.first) {
                swap(best.first, best.second);
                best.first = cur;
            } else if (cur > best.second) {
                best.second = cur;
            }
        }
        
        if (best.first + best.second + 1 >= k) {
            res++;
            lens[v] = mp(-1, -1);
        } else {
            lens[v] = best;
        }
    }
    
    return res;
}

int main() {
    cin >> n;
    
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        //x = i + 1;
        //y = i + 2;
        
        ed[x].push_back(y);
        ed[y].push_back(x);
    }
    
    dfs(1, -1);
    
    for (int i = 1; i <= n; i++) {
        ver.push_back(mp(g[i], i));
    }
    
    sort(ver.rbegin(), ver.rend());
    
    bool fl = false;
    
    for (int i = 1; i <= n; ) {
        if (!fl) {
            ans[i] = get_ans(i);
            if (ans[i] <= sq) {
                fl = true;
            }
            i++;
        } else {
            int l = i;
            int r = n;
            
            int x = get_ans(i);
            
            while (l != r) {
                int m = (l + r + 1) >> 1;
                
                if (get_ans(m) == x) {
                    l = m;
                } else {
                    r = m - 1;
                }
            }
            
            while (i <= l) {
                ans[i] = x;
                i++;
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        printf("%d\n", ans[i]);
    }
    
    return 0;
}