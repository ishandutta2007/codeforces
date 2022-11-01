/// Alexandr Tsaplin 19.08.16

#include "bits/stdc++.h"
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define TASK_NAME "a"

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 1e3 + 1;
const ll INF = 2e16 + 1;
const ll MOD = 1e9 + 7;

struct Cell {
    Cell *l, *d, *r, *u;
    int val;
    Cell() {}
    Cell(int val): val(val), l(NULL), r(NULL), d(NULL), u(NULL) {}
    Cell(int val, Cell *l, Cell *d, Cell *r, Cell *u): val(val), l(l), d(d), r(r), u(u) {}
};

Cell *cells[N][N];
int answer[N][N];

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    ios_base::sync_with_stdio(false);
    int n, m, q;
    cin >> n >> m >> q;

    fr(i, n)
        fr(j, m) {
            int x;
            cin >> x;
            cells[i][j] = new Cell(x);
        }

    fr(i, n)
        fr(j, m) {
            if (j == 0)
                cells[i][j]->l = NULL;
            else
                cells[i][j]->l = cells[i][j - 1];
            if (i == n - 1)
                cells[i][j]->d = NULL;
            else
                cells[i][j]->d = cells[i + 1][j];
            if (j == m - 1)
                cells[i][j]->r = NULL;
            else
                cells[i][j]->r = cells[i][j + 1];
            if (i == 0)
                cells[i][j]->u = NULL;
            else
                cells[i][j]->u = cells[i - 1][j];
        }

    Cell *begcell = cells[0][0];
    fr(i1, q) {
        int x1, y1, x2, y2, height, width;
        cin >> x1 >> y1 >> x2 >> y2 >> height >> width;

        Cell *cur1 = begcell;
        Cell *cur2 = begcell;

        if (x1 > x2 || x1 == x2 && y1 > y2) {
            swap(x1, x2);
            swap(y1, y2);
        }

        if (x1 == 1 && y1 == 1) {
            fr(i, x2 - 1)
                begcell = begcell->d;
            fr(i, y2 - 1)
                begcell = begcell->r;
        }

        fr(i, x1 - 1)
            cur1 = cur1->d;
        fr(i, y1 - 1)
            cur1 = cur1->r;
        fr(i, x2 - 1)
            cur2 = cur2->d;
        fr(i, y2 - 1)
            cur2 = cur2->r;

        fr(i, height) {
            if (i) {
                cur1 = cur1->d;
                cur2 = cur2->d;
            }
            swap(cur1->l, cur2->l);
            if (cur1->l)
                cur1->l->r = cur1;
            if (cur2->l)
                cur2->l->r = cur2;
        }

        fr(i, width) {
            if (i) {
                cur1 = cur1->r;
                cur2 = cur2->r;
            }
            swap(cur1->d, cur2->d);
            if (cur1->d)
                cur1->d->u = cur1;
            if (cur2->d)
                cur2->d->u = cur2;
        }

        fr(i, height) {
            if (i) {
                cur1 = cur1->u;
                cur2 = cur2->u;
            }
            swap(cur1->r, cur2->r);
            if (cur1->r)
                cur1->r->l = cur1;
            if (cur2->r)
                cur2->r->l = cur2;
        }

        fr(i, width) {
            if (i) {
                cur1 = cur1->l;
                cur2 = cur2->l;
            }
            swap(cur1->u, cur2->u);
            if (cur1->u)
                cur1->u->d = cur1;
            if (cur2->u)
                cur2->u->d = cur2;
        }
        //assert(cur1 == cells[x1 - 1][y1 - 1]);
    }


    Cell *begcell1 = cells[0][0];
    fr(i, n)
        fr(j, m)
            if (!cells[i][j]->l && !cells[i][j]->u) {
                begcell1 = cells[i][j];
                //cout << i << " " << j << endl;
            }
    fr(i, n) {
        Cell *curcell = begcell1;
        assert(curcell->r);
        fr(j, m) {
            //cout << i << " " << j << " " << curcell->val << endl;
            answer[i][j] = curcell->val;
            if (j < m - 1)
                assert(curcell->r);
            curcell = curcell->r;
        }
        begcell1 = begcell1->d;
    }

    fr(i, n) {
        fr(j, m)
            cout << answer[i][j] << " ";
        cout << endl;
    }

//    cout << fixed << setprecision(12) << a << " " << b;
}