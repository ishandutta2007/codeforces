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

unordered_set<int> was;
int t[33];
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int n;

unordered_set<lint> mem;

void dfs(int x, int y, int dir, int rest, int i) {
    lint id = ((((x + 1000LL) * 10000 + (y + 1000)) * 10LL + dir) * 10 + rest) * 100 + i;
    if (mem.find(id) != mem.end()) {
        return;
    }
    mem.insert(id);
    was.insert((x + 1000) * 10000 + y + 1000);
    --rest;

    if (rest == 0) {
        if (i == n - 1) {
            return;
        }
        ++i;
        int d1 = (dir + 1) % 8;
        int d2 = (dir - 1 + 8) % 8;
        dfs(x + dx[d1], y + dy[d1], d1, t[i], i);
        dfs(x + dx[d2], y + dy[d2], d2, t[i], i);
    } else {
        x += dx[dir];
        y += dy[dir];
        dfs(x, y, dir, rest, i);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    sci(n);
    for (int i = 0; i < n; i++) {
        sci(t[i]);
    }

    dfs(0, 0, 0, t[0], 0);
    cout << was.size();

    return 0;
}