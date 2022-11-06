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

int c[111111];
vector<int> g[111111];

lint ans[111111];
map<int, int>* cnt[111111];
set<pair<int, int>>* cs[111111];
lint ca[111111];

void dfs(int v, int p) {
    cnt[v] = new map<int, int>;
    cnt[v]->operator[](c[v])++;
    cs[v] = new set<pair<int, int>>;
    cs[v]->insert({1, c[v]});
    ca[v] = c[v];
    for (int i : g[v]) {
        if (i == p) {
            continue;
        }
        dfs(i, v);
        if (cnt[v]->size() < cnt[i]->size()) {
            swap(cnt[v], cnt[i]);
            swap(cs[v], cs[i]);
            swap(ca[v], ca[i]);
        }
        for (auto p : (*cnt[i])) {
            auto it = cnt[v]->find(p.first);
            int omx = cs[v]->rbegin()->first;
            if (it != cnt[v]->end()) {
                cs[v]->erase({it->second, it->first});
            }
            cnt[v]->operator[](p.first) += p.second;
            it = cnt[v]->find(p.first);
            cs[v]->insert({it->second, it->first});
            if (omx < cs[v]->rbegin()->first) {
                ca[v] = 0;
            }
            if (it->second == cs[v]->rbegin()->first) {
                ca[v] += 1LL * it->first;
            }
        }
    }
    ans[v] = ca[v];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n);
    for (int i = 0; i < n; i++) {
        sci(c[i]);
    }
    for (int i = 1; i < n; i++) {
        scid(x, y);
        --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    
    dfs(0, -1);
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    

    return 0;
}