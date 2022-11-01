#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;
const int NMAX = 200005, MOD = 1e9 + 7;

vector<int> G[NMAX];

struct Query {
    int type, v;
};
Query queries[NMAX];
int values[NMAX];
int level[NMAX], father[NMAX];
int euler1[2 * NMAX], first1[NMAX], last1[NMAX], eu1;
int euler2[2 * NMAX], first2[NMAX], last2[NMAX], eu2;

int aib[2 * NMAX];
int deg[NMAX];

void aib_update(int pos, int val) {
    for (; pos < 2 * NMAX - 5; pos += pos & -pos) {
        aib[pos] = (int64_t) aib[pos] * val % MOD;
    }
}

int aib_query(int pos) {
    int ret = 1;
    for (; pos > 0; pos -= pos & -pos)
        ret = (int64_t) ret * aib[pos] % MOD;
    return ret;
}

int aint[4 * 2 * NMAX], lazy[4 * 2 * NMAX];
int vint[4 * 2 * NMAX];

void build(int node, int left, int right) {
    aint[node] = 1;
    lazy[node] = 1;
    vint[node] = 0;
    if (left == right) return;
    int mid = (left + right) / 2;
    build(2 * node + 1, left, mid);
    build(2 * node + 2, mid + 1, right);
}


void split(int node, int left, int right) {
    if (lazy[node] == 1) return;
    aint[node] = (int64_t) aint[node] * lazy[node] % MOD;
    vint[node] = (int64_t) vint[node] * lazy[node] % MOD;
    if (left < right) {
        lazy[2 * node + 1] = (int64_t) lazy[2 * node + 1] * lazy[node] % MOD;
        lazy[2 * node + 2] = (int64_t) lazy[2 * node + 2] * lazy[node] % MOD;
    }
    lazy[node] = 1;
}

int aint_update_pos(int node, int left, int right, int pos, int val) {
    split(node, left, right);
    if (left == right) {
        vint[node] = (int64_t) val * aint[node] % MOD;
        //cerr << "update_pos: " << vint[node] << endl;
    } else {
        int mid = (left + right) / 2;
        if (pos <= mid) aint_update_pos(2 * node + 1, left, mid, pos, val);
        else aint_update_pos(2 * node + 2, mid + 1, right, pos, val);
        split(2 * node + 1, left, mid);
        split(2 * node + 2, mid + 1, right);
        vint[node] = (vint[2 * node + 1] + vint[2 * node + 2]) % MOD;
    }
}

void aint_update(int node, int left, int right, int lq, int rq, int val) {
    split(node, left, right);
    if (lq <= left && right <= rq) {
        lazy[node] = (int64_t) lazy[node] * val % MOD;
    } else {
        int mid = (left + right) / 2;
        if (lq <= mid) 
            aint_update(2 * node + 1, left, mid, lq, rq, val);
        if (rq > mid)
            aint_update(2 * node + 2, mid + 1, right, lq, rq, val);
        split(2 * node + 1, left, mid);
        split(2 * node + 2, mid + 1, right);
        vint[node] = (vint[2 * node + 1] + vint[2 * node + 2]) % MOD;
    }
}

int aint_query(int node, int left, int right, int lq, int rq) {
    split(node, left, right);
    if (lq <= left && right <= rq) {
        return vint[node];
    } else {
        int mid = (left + right) / 2, ret = 0;
        if (lq <= mid)
            ret = aint_query(2 * node + 1, left, mid, lq, rq);
        if (rq > mid)
            ret = (ret + aint_query(2 * node + 2, mid + 1, right, lq, rq)) % MOD;
        return ret;
    }
}

int Pow(int x, int y) {
    int ret = 1;
    for (; y > 0; y /= 2) {
        if (y & 1) ret = (int64_t) ret * x % MOD;
        x = (int64_t) x * x % MOD;
    }
    return ret;
}

int invmod(int x) {
    return Pow(x, MOD - 2);
}

void dfs(int node, int prev) {
    //cerr << node << '\n';
    euler1[++eu1] = node;
    first1[node] = eu1;
    father[node] = prev;
    level[node] = level[prev] + 1;

    euler2[++eu2] = node;
    first2[node] = eu2;

    for (int p: G[node]) {
        dfs(p, node);
    }
    euler2[++eu2] = node;
    last2[node] = eu2;

    last1[node] = eu1;
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int q;
    cin >> values[1] >> q;
    
    int n = 1;
    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;
        queries[i].type = type;
        if (type == 1) {
            int p, v;
            cin >> p >> v;
            queries[i].v = ++n;
            values[n] = v;
            G[p].push_back(n);
        } else {
            cin >> queries[i].v;
        }
    }

    dfs(1, 0);
    build(0, 1, eu1);
    aint_update_pos(0, 1, eu1, 1, values[1]);

    for (int i = 1; i <= n; ++i) {
        deg[i] = 1;
    }
    for (int i = 1; i <= 2 * n; ++i)
        aib[i] = 1;

    for (int i = 0; i < q; ++i) {
        if (queries[i].type == 1) {
            int node = queries[i].v;
            int f = father[node];
            //cerr << "query: " << node << ' '  << f << endl;

            int value = (int64_t) invmod(deg[f]) * (deg[f] + 1) % MOD;
            //cerr << "update: " << value << endl;
            //cerr << "here" << endl;
            //cerr << first1[f] << ' ' << last1[f] << endl;
            aint_update(0, 1, eu1, first1[f], last1[f], value);
            aint_update_pos(0, 1, eu1, first1[node], values[node]);


            aib_update(first2[f], value);
            value = (int64_t) invmod(deg[f] + 1) * deg[f] % MOD;
            aib_update(last2[f], value);

            deg[f]++;
        } else {
            int node = queries[i].v;

            int value = aint_query(0, 1, eu1, first1[node], last1[node]);
            //cerr << first1[node] << ' ' << last1[node] << endl;
            int v1 = aib_query(first2[node] - 1);
            //cerr << value << endl;
            value = (int64_t) value * invmod(aib_query(first2[node] - 1)) % MOD;

            cout << value << '\n';
        }
    }
}