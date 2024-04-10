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

vector<int> g[111111];
int ds[111111];

void fds(int v, int p, int d) {
    ds[v] = d;
    for (int i : g[v]) {
        if (i != p) {
            fds(i, v, d + 1);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n, m);
    for (int i = 0; i < m; i++) {
        scid(x, y);
        --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    fds(0, -1, 0);
    int x = max_element(ds, ds + n) - ds;
    memset(ds, 0, sizeof(ds));
    fds(x, -1, 0);
    cout << *max_element(ds, ds + n);



    return 0;
}