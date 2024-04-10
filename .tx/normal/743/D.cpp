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

vector<int> g[222222];
int a[222222];
lint s[222222];
lint m[222222][2];
lint mx[222222];

const lint INF = 1e18;

void relax(lint& m0, lint& m1, lint x) {
    if (x > m0) {
        m1 = m0;
        m0 = x;
    } else if (x > m1) {
        m1 = x;
    }
}

void dfs(int v, int p) {
    s[v] = a[v];
    mx[v] = -INF;
    for (int i : g[v]) {
        if (i == p) {
            continue;
        }
        dfs(i, v);
        s[v] += s[i];
        mx[v] = max(mx[v], mx[i]);
    }
    mx[v] = max(mx[v], s[v]);

    m[v][0] = -INF;
    m[v][1] = -INF;
    
    for (int i : g[v]) {
        if (i == p) {
            continue;
        }
        relax(m[v][0], m[v][1], mx[i]);
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
    lint ans = -INF;
    for (int i = 0; i < n; i++) {
        if (m[i][1] != -INF) {
            ans = max(ans, m[i][0] + m[i][1]);
        }
    }
    
    if (ans == -INF) {
        cout << "Impossible";
    } else {
        cout << ans;
    }

    return 0;
}