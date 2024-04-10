#include <bits/stdc++.h>
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define fr(i, n) for (ll i = 0; i < n; i++)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pr;

const ll M = 2e6 + 10;
const ll INF = 2e9 + 10;
const ll N = 2e6 + 10;
const ll MOD = 1e9 + 7;

int n, m;

int f(int i, int j) {
    return i * m + j;
}

struct tn {
    int val, x, y;
    tn() {}
    tn(int val, int x, int y): val(val), x(x), y(y) {}
};

int cnt[N], curcnt[N], parent[N], rnk[N];

void buildS(int x, int y) {
    int v = f(x, y);
    parent[v] = v;
    rnk[v] = 1;
}

int rootS(int x, int y) {
    int v = f(x, y);
    if (parent[v] == v)
        return v;
    parent[v] = rootS(parent[v] / m, parent[v] % m);
    return parent[v];
}

void unionS(int x1, int y1, int x2, int y2) {
    int a = f(x1, y1), b = f(x2, y2);
    int a1 = rootS(x1, y1);
    int b1 = rootS(x2, y2);
    if (a1 == b1) return;
    if (rnk[a1] > rnk[b1])
        swap(a1, b1);
    if (rnk[a1] == rnk[b1]) {
        parent[b1] = a1;
        rnk[a1]++;
    }
    else {
        parent[a1] = b1;
    }
}

bool cmp1(tn a, tn b) {
    if (a.val != b.val)
        return a.val < b.val;
    return a.y < b.y;
}

bool cmp2(tn a, tn b) {
    if (a.val != b.val)
        return a.val < b.val;
    return a.x < b.x;
}

vector <int> g[N];

int used[N];

void dfs(int i, int j, int cur) {
    used[f(i, j)] = cur;
    fr(i1, g[f(i, j)].size()) {
        curcnt[g[f(i, j)][i1]]++;
        used[g[f(i, j)][i1]] = max(used[g[f(i, j)][i1]], cur + 1);
        if (cnt[g[f(i, j)][i1]] == curcnt[g[f(i, j)][i1]])
            dfs(g[f(i, j)][i1] / m, g[f(i, j)][i1] % m, max(used[g[f(i, j)][i1]], cur + 1));
    }
}

int main() {
    //freopen("a.in", "r", stdin);
    cin >> n >> m;
    vector <vector <tn> > a(n), b(m), c(n);
    fr(i, n)
        a[i].resize(m);
    fr(i, m)
        b[i].resize(n);
    fr(i, n)
        c[i].resize(m);

    fr(i, n)
        fr(j, m) {
            cin >> a[i][j].val;
            c[i][j].val = a[i][j].val;
            a[i][j].x = i, a[i][j].y = j;
            b[j][i].val = a[i][j].val;
            b[j][i].x = i, b[j][i].y = j;
        }

    fr(i, n)
        sort(a[i].begin(), a[i].end(), cmp1);
    fr(i, m)
        sort(b[i].begin(), b[i].end(), cmp2);

    fr(i, n)
        fr(j, m)
            buildS(i, j);

    fr(i, n)
        fr(j, m - 1)
            if (a[i][j].val == a[i][j + 1].val)
                unionS(a[i][j].x, a[i][j].y, a[i][j + 1].x, a[i][j + 1].y);

    fr(i, m)
        fr(j, n - 1)
            if (b[i][j].val == b[i][j + 1].val)
                unionS(b[i][j].x, b[i][j].y, b[i][j + 1].x, b[i][j + 1].y);

    fr(i, n)
        fr(j, m - 1)
            if (a[i][j].val != a[i][j + 1].val) {
                g[rootS(a[i][j].x, a[i][j].y)].pb(rootS(a[i][j + 1].x, a[i][j + 1].y));
                cnt[rootS(a[i][j + 1].x, a[i][j + 1].y)]++;
            }

    fr(i, m)
        fr(j, n - 1)
            if (b[i][j].val != b[i][j + 1].val) {
                g[rootS(b[i][j].x, b[i][j].y)].pb(rootS(b[i][j + 1].x, b[i][j + 1].y));
                cnt[rootS(b[i][j + 1].x, b[i][j + 1].y)]++;
            }

    fr(i, n)
        fr(j, m)
            if (!cnt[rootS(i, j)] && !used[rootS(i, j)])
                dfs(i, j, 1);

    fr(i, n) {
        fr(j, m)
            cout << used[rootS(i, j)] << " ";cout << endl;}


}