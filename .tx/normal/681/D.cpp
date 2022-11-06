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
};

#define scid(vars...) int vars; sci(vars)
#define scidl(vars...) lint vars; sci(vars)
#define scidd(vars...) double vars; sci(vars)
#define scids(vars...) string vars; sci(vars)

typedef long long lint;

int p[111111];
bool ban[111111];
vector<int> g[111111];
vector<int> ts;
bool used[111111];
int a[111111];

void dfs(int v) {
    if (used[v]) {
        return;
    }
    used[v] = true;
    for (int i : g[v]) {
        dfs(i);
    }
    ts.push_back(v);
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n, m);
    for (int i = 0; i < m; i++) {
        scid(x, y);
        --x; --y;
        p[y] = x;
        g[x].push_back(y);
    }

    for (int i = 0; i < n; i++) {
        scid(x);
        --x;
        a[i] = x;
        int c = i;
        while (c != x) {
            ban[c] = true;
            c = p[c];
        }
    }

    for (int i = 0; i < n; i++) {
        if (ban[a[i]]) {
            cout << -1;
            return 0;
        }
    }



    for (int i = 0; i < n; i++) {
        dfs(i);
    }

//    reverse(ts.begin(), ts.end());

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (!ban[ts[i]]) {
            ans.push_back(ts[i]);
        }
    }
    cout << ans.size() << "\n";
    for (int i : ans) {
        cout << i + 1 << "\n";
    }


    return 0;
}