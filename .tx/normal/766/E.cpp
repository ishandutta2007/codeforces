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

template <typename T>
using heap = priority_queue<T, vector<T>, std::greater<T>>;

typedef long long lint;

int a[111111];
vector<int> g[111111];

lint cd[111111][22][2];
lint ct[111111][22][2];

void dfs(int v, int p) {
    for (int i = 0; i < 22; i++) {
        if ((a[v] >> i) & 1) {
            cd[v][i][1] = 1;
            ct[v][i][1] = 1;
        } else {
            cd[v][i][0] = 1;
            ct[v][i][0] = 1;
        }
    }
    
    for (int i : g[v]) {
        if (i == p) {
            continue;
        }
        dfs(i, v);
    }
    
    for (int b = 0; b < 22; b++) {
        lint s0 = 0;
        lint s1 = 0;
        for (int i : g[v]) {
            if (i != p) {
                s0 += cd[i][b][0];
                s1 += cd[i][b][1];
            }
        }
        
        int cb = (a[v] >> b) & 1;
        
        if (cb) {
            cd[v][b][0] += s1;
            ct[v][b][0] += s1;
            cd[v][b][1] += s0;
            ct[v][b][1] += s0;
        } else {
            cd[v][b][0] += s0;
            ct[v][b][0] += s0;
            cd[v][b][1] += s1;
            ct[v][b][1] += s1;
        }
        
        s0 = s1 = 0;
        
        for (int i : g[v]) {
            if (i != p) {
                if (cb) {
                    ct[v][b][0] += cd[i][b][1] * s0 + cd[i][b][0] * s1;
                    ct[v][b][1] += cd[i][b][0] * s0 + cd[i][b][1] * s1; 
                } else {
                    ct[v][b][0] += cd[i][b][0] * s0 + cd[i][b][1] * s1;
                    ct[v][b][1] += cd[i][b][1] * s0 + cd[i][b][0] * s1;
                }
                
                s0 += cd[i][b][0];
                s1 += cd[i][b][1];
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n);
    for (int i = 0; i < n; i++) {
        sci(a[i]);
    }
    
    for (int i = 1; i < n; i++) {
        scid(x, y);
        --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    
    dfs(0, -1);
    
    lint ans = 0;
    for (int i = 0; i < n; i++) {
        for (int b = 0; b < 22; b++) {
            ans += ct[i][b][1] * (1 << b);
        }
    }
    
    cout << ans;
    

    return 0;
}