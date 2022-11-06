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

//#define debug(x) ;
#define debug(x) cerr << #x << " = " << x << "\n";

ostream& operator<<(ostream& cerr, vector<ll> aux) {
    cerr << "[";
    for (auto e : aux) cerr << e << ' ';
    cerr << "]";
    return cerr;
}

#define lSon (node << 1)
#define rSon (lSon | 1)

typedef pair<int, int>  pii;
const int maxN = 200011;
const int inf = 2000000000;

struct cmp {
    bool operator()(const pii& a, const pii& b) {
        return a > b;
    }
};

struct aint {
    pii data[maxN * 4 + 11];
    int n;

    void init(int _n) {
        n = _n;
        for (int i = 1; i <= 4 * n; i++) {
            data[i] = mp(inf, inf);
        }
    }

    void update(int pos, int val) {
        upd(1, 1, n, pos, val);
    }

    int query(int l, int r) {
        pii best = que(1, 1, n, l, r);
        if (best.second == inf) return inf;
        return best.first + best.second;
    }


    void upd(int node, int l, int r, int pos, int val) {
        if (l == r) {
            data[node] = mp(val, inf);
            return;
        }
        
        int mid = (l + r) >> 1;
        if (pos <= mid)
            upd(lSon, l, mid, pos, val);
        else
            upd(rSon, mid + 1, r, pos, val);

        data[node] = best_choice(data[lSon], data[rSon]);
    }

    pii que(int node, int l, int r, int qL, int qR) {
        if (qL <= l && r <= qR) 
            return data[node];

        int mid = (l + r) >> 1;
        pii answer = mp(inf, inf);

        if (qL <= mid) answer = que(lSon, l, mid, qL, qR);
        if (qR > mid) 
            answer = best_choice(answer, que(rSon, mid + 1, r, qL, qR));

        return answer;
    }

    pii best_choice(pii a, pii b) {
        if (a > b) swap(a, b);
        return mp(a.first, min(a.second, b.first));
    }

};

struct query {
    int type, l, r;
    int answer;
};

int n, m, base;
int initialValues[maxN];
query Q[maxN];
aint values;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);
    base = 1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &initialValues[i]);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &Q[i].type, &Q[i].l, &Q[i].r);
        Q[i].answer = inf;
    }

    for (int times = 1; times < 10; times++, base *= 10) {
        values.init(n);
        for (int i = 1; i <= n; i++) {
            int aux = (initialValues[i] / base) % 10;
            aux = (aux == 0 ? inf : initialValues[i]);

            values.update(i, aux);
        }

        for (int i = 1; i <= m; i++) {
            if (Q[i].type == 1) {
                int aux = (Q[i].r / base) % 10;
                aux = (aux == 0 ? inf : Q[i].r);
                values.update(Q[i].l, aux);
            } else {
                int aux = values.query(Q[i].l, Q[i].r);
                Q[i].answer = min(Q[i].answer, aux);
            }
        }
    }

    for (int i = 1; i <= m; i++) {
        if (Q[i].type == 1) continue;
        printf("%d\n", (Q[i].answer == inf ? -1 : Q[i].answer));
    }


    return 0;
}