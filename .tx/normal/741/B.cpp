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

int w[1111];
int b[1111];

vector<int> g[1111];
bool used[1111];

vector<vector<pair<int, int>>> a;

void dfs(int v) {
    used[v] = true;
    a.back()[0].first += w[v];
    a.back()[0].second += b[v];
    a.back().push_back({w[v], b[v]});
    
    for (int i : g[v]) {
        if (!used[i]) {
            dfs(i);   
        }
    }
}

int d[1111][1111];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n, m, k);
    
    for (int i = 0; i < n; i++) {
        sci(w[i]);
    }

    for (int i = 0; i < n; i++) {
        sci(b[i]);
    }
    
    for (int i = 0; i < m; i++) {
        scid(x, y);
        --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            a.push_back(vector<pair<int, int>>(1, {0, 0}));
            dfs(i);
        }
    }
    
    n = a.size();
//    cerr << n << endl;
//    for (auto i : a) {
//        for (auto p : i) {
//            cerr << p.first << " " << p.second << endl;
//        }
//        cerr << endl;
//    }
    for (int i = 1; i <= n; i++) {
        for (auto& p : a[i - 1]) {
            for (int j = 0; j <= k; j++) {
                d[i][j] = max(d[i][j], d[i - 1][j]);
                if (p.first <= j) {
                    d[i][j] = max(d[i][j], d[i - 1][j - p.first] + p.second);
                }
            }
        }
    }
    
    cout << *max_element(d[n], d[n] + k + 1);
    
    

    return 0;
}