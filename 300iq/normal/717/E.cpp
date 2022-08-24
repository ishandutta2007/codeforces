#include <bits/stdc++.h>

using namespace std;

int c[200000];
vector<vector<int> > g;
int pr[200000];

bool wh[200000];
bool need[200000];

bool dfs1(int v, int p){
    need[v] = wh[v];
    for (int i = 0; i < (int)g[v].size(); i++)
    if (g[v][i] != p)
        need[v] |= dfs1(g[v][i], v);
    return need[v];
}

vector<int> ans;
int gl;

bool got_ans = 0;

void dfs(int v, int p){
    for (int i = 0; i < (int)g[v].size(); i++)
    if (g[v][i] != p){
        if (need[g[v][i]]){
            ans.push_back(g[v][i] + 1);
            wh[g[v][i]] ^= 1;
            if (wh[g[v][i]])
                gl++;
            else
                gl--;
            dfs(g[v][i], v);
        }
    }

    if (gl != 0){
        if (p == v){
            ans.push_back(g[v][0] + 1);
            ans.push_back(v + 1);
            ans.push_back(g[v][0] + 1);
        }
        else{
            if (wh[v]){
                ans.push_back(p + 1);
                wh[p] ^= 1;
                if (wh[p])
                    gl++;
                else
                    gl--;
                ans.push_back(v + 1);
                wh[v] = 0;
                gl--;
                if (gl != 0){
                    ans.push_back(p + 1);
                    wh[p] ^= 1;
                    if (wh[p])
                        gl++;
                    else
                        gl--;
                }
            }
            else{
                if (gl != 0){
                    ans.push_back(p + 1);
                    wh[p] ^= 1;
                    if (wh[p])
                        gl++;
                    else
                        gl--;
                }
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    g.resize(n);
    int memcnt = 0;
    for (int i = 0; i < n; i++){
        cin >> c[i];
        if (c[i] == -1)
            wh[i] = 1, memcnt++, gl++;
    }

    if (!memcnt){
        cout << 1;
        return 0;
    }

    for (int i = 0; i < n - 1; i++){
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs1(0, 0);

    dfs(0, 0);

    cout << 1 << ' ';
    for (int i = 0; i < (int)ans.size(); i++)
        cout << ans[i] << ' ';
}