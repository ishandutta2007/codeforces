#include <bits/stdc++.h>
using namespace std;

template<typename T>
void sci(T& t) {
    cin >> t;
}

template<typename T, typename... Ts>
void sci(T& t, Ts&... ts) {
    sci(t);
    sci(ts...);
}

#define scid(vars...) int vars; sci(vars)
#define scidl(vars...) lint vars; sci(vars)
#define scidd(vars...) double vars; sci(vars)
#define scids(vars...) string vars; sci(vars)

typedef long long lint;

vector<int> g[3333];
vector<int> rg[3333];

int d[3333][3333];
int rd[3333][3333];

vector<int> t3[3333];
vector<int> rt3[3333];

int n, m;

pair<int, int> tt[3333];

void calc(int v, int* d, vector<int>* g, vector<int>& t3) {
    memset(d, -1, sizeof(int) * 3333);
    
    d[v] = 0;
    queue<int> q;
    q.push(v);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        
        for (int i : g[v]) {
            if (d[i] == -1 || d[i] > d[v] + 1) {
                d[i] = d[v] + 1;
                q.push(i);
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        tt[i] = {d[i], i};
    }
    
    sort(tt, tt + n);
    reverse(tt, tt + n);
    
    for (int i = 0; i < 3 && tt[i].first > 0; i++) {
        t3.push_back(tt[i].second);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    sci(n, m);
    for (int i = 0; i < m; i++) {
        scid(x, y);
        --x; --y;
        if (x != y) {
            g[x].push_back(y);
            rg[y].push_back(x);
        }
    }
    
    for (int i = 0; i < n; i++) {
        calc(i, d[i], g, t3[i]);
        calc(i, rd[i], rg, rt3[i]);
    }
    
    int ans = -1;
    int a1 = -1;
    int a2 = -1;
    int a3 = -1;
    int a4 = -1;
    
    
    for (int a = 0; a < n; a++) {
        for (int b = 0; b < n; b++) {
            if (a == b) {
                continue;
            }
            if (d[a][b] == -1) {
                continue;
            }
            for (int i : rt3[a]) {
                for (int j : t3[b]) {
                    if (i == b || i == a || j == b || j == a || i == j) {
                        continue;
                    }
                    int t = d[i][a] + d[a][b] + d[b][j];
                    if (t > ans) {
                        ans = t;
                        a1 = i;
                        a2 = a;
                        a3 = b;
                        a4 = j;
                    }
                }
            }
        }
    }
    
    printf("%d %d %d %d", a1 + 1, a2 + 1, a3 + 1, a4 + 1);
    
    return 0;
}