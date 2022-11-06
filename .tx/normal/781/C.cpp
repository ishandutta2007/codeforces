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

vector<vector<int>> ans;
int lim;
bool used[222222];

void dfs(int v) {
    used[v] = true;
    ans.back().push_back(v);
    if (ans.back().size() == lim) {
        ans.push_back(vector<int>());
    }
    for (int i : g[v]) {
        if (!used[i]) {
            dfs(i);
            ans.back().push_back(v);
            if (ans.back().size() == lim) {
                ans.push_back(vector<int>());
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    scid(n, m, k);
    lim = (2 * n + k - 1) / k;
    for (int i = 0; i < m; i++) {
        scid(x, y);
        --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    ans.push_back(vector<int>());
    dfs(0);
    while (ans.size() <= k) {
        if (ans.back().empty()) {
            ans.back().push_back(0);
        }
        ans.push_back(vector<int>());
    }

    for (int i = 0; i < k; i++) {
        cout << ans[i].size();
        for (int j : ans[i]) {
            cout << " " << j + 1;
        }
        cout << "\n";
    }


    return 0;
}