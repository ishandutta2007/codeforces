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

int r[111111];

vector<int> cc[111111];

vector<int> g[222222];
vector<int> rg[222222];

void add_edge(int x, int y) {
    g[x ^ 1].push_back(y);
    rg[y].push_back(x ^ 1);

    g[y ^ 1].push_back(x);
    rg[x].push_back(y ^ 1);
}

vector<int> ts;
bool used1[222222];
void dfs1(int v) {
    used1[v] = true;
    for (int i : g[v]) {
        if (!used1[i]) {
            dfs1(i);
        }
    }
    ts.push_back(v);
}

int c[222222];

bool used2[222222];
void dfs2(int v, int cn) {
    used2[v] = true;
    c[v] = cn;
    for (int i : rg[v]) {
        if (!used2[i]) {
            dfs2(i, cn);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    scid(n, m);
    for (int i = 0; i < n; i++) {
        sci(r[i]);
    }

    for (int i = 0; i < m; i++) {
        scid(x);
        for (int j = 0; j < x; j++) {
            scid(y);
            --y;
            cc[y].push_back(i);
        }
    }

    for (int i = 0; i < n; i++) {
        if (r[i]) {
            add_edge(cc[i][0] * 2, cc[i][1] * 2 + 1);
            add_edge(cc[i][0] * 2 + 1, cc[i][1] * 2);
        } else {
            add_edge(cc[i][0] * 2, cc[i][1] * 2);
            add_edge(cc[i][0] * 2 + 1, cc[i][1] * 2 + 1);
        }
    }

    for (int i = 0; i < 2 * m; i++) {
        if (!used1[i]) {
            dfs1(i);
        }
    }

    reverse(ts.begin(), ts.end());
    int cn = 0;
    for (int i = 0; i < 2 * m; i++) {
        if (!used2[ts[i]]) {
            dfs2(ts[i], cn++);
        }
    }

//    cerr << cn << endl;

    for (int i = 0; i < m; i++) {
        if (c[i * 2] == c[i * 2 + 1]) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";


    return 0;
}