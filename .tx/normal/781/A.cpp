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

template <typename T, typename Cmp=std::greater<int>>
using heap = priority_queue<T, std::vector<T>, Cmp>;

typedef long long lint;

vector<int> g[222222];
int ans[222222];
int mx = 1;

void dfs(int v, int p) {
    int c = 0;
    for (int i : g[v]) {
        if (i == p) {
            continue;
        }
        c++;
        while (c == ans[v] || (p != -1 && c == ans[p])) {
            c++;
        }
        ans[i] = c;
        dfs(i, v);
    }
    mx = max(mx, c);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    scid(n);
    for (int i = 1; i < n; i++) {
        scid(x, y);
        --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    ans[0] = 1;
    dfs(0, -1);

    cout << mx << "\n";
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }


    return 0;
}