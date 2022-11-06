#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

const int maxN = 200011;
const int maxLog = 20;

class Buffer {
    public:
        Buffer(int _dim) {
            dim = _dim;
            data.resize(dim + 11);
            refill();
        }

        Buffer& operator>>(int &dest) {
            while (!is_digit(data[pos]))
                if (++pos == dim)
                    refill();

            dest = 0;
            while (is_digit(data[pos])) {
                dest = dest * 10 + data[pos] - '0';
                if (++pos == dim)
                    refill();
            }   
            return *this;
        }

    private:
        int dim, pos;
        vector<char> data;

        bool is_digit(char c) {
            return '0' <= c && c <= '9';
        }

        void refill() {
            pos = 0;
            memset(&data[0], 0, dim);
            fread(&data[0], 1, dim, stdin);
        }
};

int n, m, q, i, x, y;
vector<int> list[maxN];
int eu_in[maxN], eu_out[maxN], cnt;
int dad[maxLog][maxN], lvl[maxN], up[maxLog][maxN];
pair<int, int> buses[maxN], Q[maxN];
vector<int> add[maxN];
vector< pair<int, int> > to_ask[maxN];
int ans[maxN], aux[maxN];
int fen[maxN];

int zrs(int x) {
    return (x ^ (x - 1)) & x;
}

void add_fen(int x, int v) {
    while (x <= n) {
        fen[x] += v;
        x += zrs(x);
    }
}

int sum_fen(int x) {
    int ans = 0;
    while (x > 0) {
        ans += fen[x];
        x -= zrs(x);
    }
    return ans;
}

void dfs(int node) {
    eu_in[node] = ++cnt;
    for (auto to : list[node]) {
        lvl[to] = lvl[node] + 1; 
        dfs(to);
    }
    eu_out[node] = cnt;
}

void compute_dad() {
    int i, j;

    for (i = 1; i < maxLog; i++) {
        for (j = 1; j <= n; j++)
            dad[i][j] = dad[i - 1][dad[i - 1][j]];
    }
}

void go_up(int &node, int cnt) {
    for (int i = 0; cnt > 0; i++, cnt >>= 1)
        if (cnt & 1)
            node = dad[i][node];
}

int get_lca(int x, int y) {
    if (lvl[x] < lvl[y]) swap(x, y);
    go_up(x, lvl[x] - lvl[y]);
    if (x == y) return x;
    for (int i = maxLog - 1; i >= 0; i--)
        if (dad[i][x] != dad[i][y])
            x = dad[i][x], y = dad[i][y];
    return dad[0][x];
}

void compute_up() {
    int i, j;

    for (i = 1; i < maxLog; i++)
        for (j = 1; j <= n; j++)
            up[i][j] = up[i - 1][up[i - 1][j]];
}

int get_need(int &x, int limit) {
   int ans = 0;

   for (int i = maxLog - 1; i >= 0; i--)
        if (lvl[up[i][x]] > limit)
            x = up[i][x], ans += (1 << i);
    
    return ans;
}

void dfs_up(int node) {
    for (auto to : list[node]) {
        dfs_up(to);
        if (lvl[up[0][node]] > lvl[up[0][to]])
            up[0][node] = up[0][to];
    }
}

void add_query(int x, int y, int id) {
    if (eu_in[x] > eu_in[y])
        swap(x, y);
    to_ask[x].pb(mp(y, id));
}

void solve(int x, int y, int id) {
    int lca = get_lca(x, y);

    int need_x = get_need(x, lvl[lca]);
    int need_y = get_need(y, lvl[lca]);


    if (lvl[up[0][x]] > lvl[lca]) {
        ans[id] = -1;
        return;
    }

    if (lvl[up[0][y]] > lvl[lca]) {
        ans[id] = -1;
        return;
    }

    if (x == lca) {
        ans[id] = need_y + 1;
        return;
    }

    if (y == lca) {
        ans[id] = need_x + 1;
        return;
    }

    //! worst case is expected, -1 otherwise
    ans[id] = need_x + need_y + 2; 
    add_query(x, y, id);
}

void dfs_query(int node) {

    for (auto e : to_ask[node]) {
        aux[e.second] -= sum_fen(eu_out[e.first]);
        aux[e.second] += sum_fen(eu_in[e.first] - 1);
    }


    for (auto to : list[node])
        dfs_query(to);

    for (auto e : add[node]) {
        add_fen(eu_in[e], +1);
    }



    for (auto e : to_ask[node]) {
        
        aux[e.second] += sum_fen(eu_out[e.first]);
        aux[e.second] -= sum_fen(eu_in[e.first] - 1);
        if (aux[e.second] < 0) {
            cerr << "Error 160\n";
        }
        if (aux[e.second] > 0) ans[e.second]--;
    }   
    
}

int main()
{
    //freopen("test.in","r",stdin);
    Buffer fin(1 << 20);

    fin >> n;
    for (i = 2; i <= n; i++) {
        fin >> x;
        list[x].pb(i);
        dad[0][i] = x;
    }

    dfs(1);
    compute_dad();

    for (i = 1; i <= n; i++) up[0][i] = i;

    fin >> m;
    for (i = 1; i <= m; i++) {
        fin >> buses[i].first >> buses[i].second;
        if (eu_in[buses[i].first] > eu_in[buses[i].second])
            swap(buses[i].first, buses[i].second);
        add[buses[i].first].pb(buses[i].second);
    
        x = buses[i].first;
        y = buses[i].second;
        int lca = get_lca(x, y);
        if (lvl[lca] < lvl[up[0][x]])
            up[0][x] = lca;
        if (lvl[lca] < lvl[up[0][y]])
            up[0][y] = lca;
    }
    
    dfs_up(1);
    compute_up();

    fin >> q;
    for (i = 1; i <= q; i++) {
        fin >> x >> y;
        solve(x, y, i);
    }

    dfs_query(1);

    for (i = 1; i <= q; i++)
        printf("%d\n", ans[i]);

    return 0;
}