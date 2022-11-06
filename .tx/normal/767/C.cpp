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
using heap = priority_queue<T, std::vector<T>, std::greater<T>>;

typedef long long lint;

vector<int> g[1111111];
int s[1111111];
int t[1111111];
int lf, rt;

int dfs(int v, int p) {
    s[v] = t[v];
    vector<int> a;
    for (int i : g[v]) {
        if (i == p) {
            continue;
        }
        int x = dfs(i, v);
        if (x != -1) {
            a.push_back(x);
        }
        s[v] += s[i];
    }
    if (a.size() >= 2) {
        cout << a[0] + 1 << " " << a[1] + 1;
        exit(0);
    }

    if (v != rt && s[v] == 2 * lf && !a.empty()) {
        cout << v + 1 << " " << a[0] + 1;
        exit(0);
    }

    if (s[v] == lf) {
        a.push_back(v);
    }
    if (a.empty()) {
        return -1;
    }
    return a[0];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    scid(n);
    int s = 0;
    for (int i = 0; i < n; i++) {
        scid(x, y);
        --x;
        if (x == -1) {
            rt = i;
        } else {
            g[i].push_back(x);
            g[x].push_back(i);
        }
        t[i] = y;
        s += y;
    }

    if (s % 3 != 0) {
        cout << -1;
        return 0;
    }

    lf = s / 3;

    dfs(rt, -1);

    cout << -1;



    return 0;
}