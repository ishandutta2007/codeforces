#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define lSon (node << 1)
#define rSon (lSon | 1)

#define mod 1000000007
#define maxN 100011

struct matrix {
    static const int n = 4;
    ll data[n][n];

    void init() {
        memset(data, 0, sizeof(data));
        data[0][0] = data[1][1] = data[2][2] = data[3][3] = 1;
    }

    void zero() {
        memset(data, 0, sizeof(data));
    }

    matrix operator*(matrix who) {
        static matrix ans;
        static int i, j, k;

        ans.zero();
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                for (k = 0; k < n; k++)
                    ans.data[i][j] += (data[i][k] * who.data[k][j]) % mod;
                ans.data[i][j] %= mod;
            }
        }

        return ans;
    }
};

struct aint {
    int dim;
    vector<matrix> data;
    matrix* from;

    void build(int node, int l, int r) {
        if (l == r) {
            data[node] = from[l];
            return;
        }

        int mid = (l + r) >> 1;
        build(lSon, l, mid);
        build(rSon, mid + 1, r);

        data[node] = data[lSon] * data[rSon];
    }

    void init(int _dim, matrix *_from) {
        dim = _dim; from = _from;
        data = vector<matrix>(4 * dim + 11);
        build(1, 1, dim);
    }

    void upd(int node, int l, int r, int pos, matrix& repl) {
        if (l == r) {
            data[node] = repl;
            return;
        }

        int mid = (l + r) >> 1;
        if (pos <= mid) upd(lSon, l, mid, pos, repl);
        else            upd(rSon, mid + 1, r, pos, repl);

        data[node] = data[lSon] * data[rSon];
    }
};

int n, i, j, k, cnt, q, tp, x;
int a[maxN];
vector<int> norm;
map<int, int> M;
vector< pair<int, int> > ord;

int where[maxN];
vector<int> pos[maxN];
int aib[maxN], pref[maxN], suf[maxN];
matrix aux[maxN];
aint work[maxN];

ll ans;

int zrs(int x) {
    return (x ^ (x - 1)) & x;
}

void add(int pos) {
    while (pos <= n) {
        aib[pos]++;
        pos += zrs(pos);
    }
}

int sum(int pos) {
    int ans = 0;
    while (pos > 0) {
        ans += aib[pos];
        pos -= zrs(pos);
    }
    return ans;
}

void init_group(int id) {
    int i, dim;
    dim = pos[id].size();

    for (i = 0; i < dim; i++) {
        aux[i + 1].init();
        aux[i + 1].data[0][1] = pref[ pos[id][i] ];
        aux[i + 1].data[1][2] = 1;
        aux[i + 1].data[2][3] = suf[ pos[id][i] ];
    }

    work[id].init(dim, aux);
    ans += work[id].data[1].data[0][3];
    ans %= mod;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        norm.pb(a[i]);
    }

    sort(norm.begin(), norm.end());
    norm.resize(unique(norm.begin(), norm.end()) - norm.begin());
    for (i = 0; i < norm.size(); i++) M[norm[i]] = i + 1, cnt = i + 1;

    for (i = 1; i <= n; i++) {
        a[i] = M[a[i]];
        pos[a[i]].pb(i); where[i] = pos[a[i]].size();
        ord.pb(mp(a[i], i));
    }

    sort(ord.begin(), ord.end());
    for (i = 0; i < ord.size(); i = j) {
        for (j = i; j < ord.size(); j++) {
            if (ord[i].first != ord[j].first) break;
            add(ord[j].second);
        }

        for (k = i; k < j; k++) {
            pref[ ord[k].second ] = sum(ord[k].second) - 1;
            suf[ ord[k].second ] = j - pref[ ord[k].second ] - 1;
        }
    }

    for (i = 1; i <= cnt; i++)
        init_group(i);

    //cerr << ans;

    scanf("%d", &q);
    for (i = 1; i <= q; i++) {
        scanf("%d%d", &tp, &x);

        if (tp == 1) {
            aux[0].init();

            ans += mod - work[ a[x] ].data[1].data[0][3];
            work[ a[x] ].upd(1, 1, pos[a[x]].size(), where[x], aux[0]);
            ans += work[ a[x] ].data[1].data[0][3];
            ans %= mod;
        } else {
            aux[0].init();
            aux[0].data[0][1] = pref[x];
            aux[0].data[1][2] = 1;
            aux[0].data[2][3] = suf[x];

            ans += mod - work[ a[x] ].data[1].data[0][3];
            work[ a[x] ].upd(1, 1, pos[a[x]].size(), where[x], aux[0]);
            ans += work[ a[x] ].data[1].data[0][3];
            ans %= mod;
        }

        printf("%lld\n", ans);
    }

    return 0;
}