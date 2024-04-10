#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define sz(a) (int)(a).size()
#define all(a) (a).begin(),a.end()
#define pw(x) (1LL<<(x))

#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << " = "; for (auto xxxx: a) cerr << xxxx << " "; cerr << endl

using namespace std;

typedef long long ll;
typedef double dbl;
const int INF = 1.01e9;



int main() {
#define TASK "A"
#ifdef HOME
    assert(freopen(TASK".in", "r", stdin));
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    vector<vector<int>> e(n);
    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            int v;
            scanf("%d",  &v); v--;
            e[i].pb(v);
        }
    }
    int s;
    scanf("%d", &s); s--;

    vector<int> used(n);
    bool draw = 0;

    function<void(int)> dfs = [&](int v) {
        used[v] = 1;
        for (auto u: e[v]) {
            if (used[u] == 1) {
                draw = 1;
            }
            if (used[u] == 0) {
                dfs(u);
            }
        }
        used[v] = 2;
    };

    dfs(s);

    bool win = 0;
    vector<vector<int>> vis(n, vector<int>(2));
    vector<int> st;
    vector<int> path;


    function<void(int, int)> dfs2 = [&](int v, int d) {
        st.pb(v);
        vis[v][d] = 1;
        if (e[v].empty() && d == 1) {
            win = 1;
            path = st;
        }
        for (auto u: e[v]) {
            if (vis[u][d ^ 1] == 0) {
                dfs2(u, d ^ 1);
            }
        }
        st.pop_back();
    };

    dfs2(s, 0);

    if (win) {
        puts("Win");
        for (auto x: path) {
            printf("%d ", x + 1);
        }
        puts("");
    }
    else if (draw) {
        puts("Draw");
    }
    else {
        puts("Lose");
    }




    return 0;
}