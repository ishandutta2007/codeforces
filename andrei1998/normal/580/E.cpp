#include <iostream>
#include <cstring>

using namespace std;

const int NMAX = 100005;

const int mod1 = 1000000009;
const int mod2 = 1000000007;

const int c1 = 1997;
const int c2 = 1999;

int pows_c1[NMAX];
int pows_c2[NMAX];
int sum_c1[NMAX];
int sum_c2[NMAX];

struct node {
    int st, dr;
    int h1, h2;

    int lazy;

    node () {
        lazy = -1;
    }

    void make_lazy (int x) {
        lazy = x;

        h1 = (1ll * sum_c1[dr - st] * x) % mod1;
        h2 = (1ll * sum_c2[dr - st] * x) % mod2;
    }
} arb[4 * NMAX];

void lazy_sons (int pos) {
    if (arb[pos].lazy != -1) {
        arb[pos << 1].make_lazy(arb[pos].lazy);
        arb[(pos << 1) + 1].make_lazy(arb[pos].lazy);

        arb[pos].lazy = -1;
    }
}

void unite (node &a, node b, node &c) {
    a.h1 = ((1ll * b.h1 * pows_c1[c.dr - c.st + 1]) % mod1 + c.h1) % mod1;
    a.h2 = ((1ll * b.h2 * pows_c2[c.dr - c.st + 1]) % mod2 + c.h2) % mod2;
}

char sir[NMAX];

void build (int st, int dr, int pos) {
    arb[pos].st = st, arb[pos].dr = dr;
    arb[pos].lazy = -1;

    if (st == dr) {
        arb[pos].h1 = arb[pos].h2 = (sir[st] - '0' + 1);
        return ;
    }

    int mijl = ((st + dr) >> 1);

    build (st, mijl, pos << 1);
    build(mijl + 1, dr, (pos << 1) + 1);

    unite(arb[pos], arb[pos << 1], arb[(pos << 1) + 1]);
}

void update (int st, int dr, int val, int pos) {
    if (arb[pos].st == st && arb[pos].dr == dr) {
        arb[pos].make_lazy(val);
        return ;
    }
    lazy_sons(pos);

    int mijl = ((arb[pos].st + arb[pos].dr) >> 1);

    if (dr <= mijl)
        update(st, dr, val, pos << 1);
    else if (st > mijl)
        update(st, dr, val, (pos << 1) + 1);
    else {
        update(st, mijl, val, pos << 1);
        update(mijl + 1, dr, val, (pos << 1) + 1);
    }

    unite(arb[pos], arb[pos << 1], arb[(pos << 1) + 1]);
}

node aux;
void query (int st, int dr, int pos) {
    if (arb[pos].st == st && arb[pos].dr == dr) {
        unite(aux, aux, arb[pos]);
        return ;
    }
    lazy_sons(pos);

    int mijl = ((arb[pos].st + arb[pos].dr) >> 1);

    if (dr <= mijl)
        query(st, dr, pos << 1);
    else if (st > mijl)
        query(st, dr, (pos << 1) + 1);
    else {
        query(st, mijl, pos << 1);
        query(mijl + 1, dr, (pos << 1) + 1);
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);

    pows_c1[0] = sum_c1[0] = 1;
    pows_c2[0] = sum_c2[0] = 1;

    for (int i = 1; i < NMAX; ++ i) {
        pows_c1[i] = (1ll * pows_c1[i - 1] * c1) % mod1;
        pows_c2[i] = (1ll * pows_c2[i - 1] * c2) % mod2;

        sum_c1[i] = sum_c1[i - 1] + pows_c1[i];
        if (sum_c1[i] >= mod1)
            sum_c1[i] -= mod1;

        sum_c2[i] = sum_c2[i - 1] + pows_c2[i];
        if (sum_c2[i] >= mod2)
            sum_c2[i] -= mod2;
    }

    int n, m, k;
    cin >> n >> m >> k;

    cin.get();
    cin.get(sir + 1, NMAX);

    build(1, n, 1);

    m += k;

    int tip, l, r, c, aa, bb, cc, dd;
    while (m --) {
        cin >> tip >> l >> r >> c;

        if (tip == 1) {
            update(l, r, c + 1, 1);
        }
        else {
            //if ((r - l + 1) % c != 0) {
            //    cout << "NO\n";
            //}
            //else {
                //cout << "query pe " << ' ' << l << ' ' << r - c << endl;
                aux.h1 = aux.h2 = 0;

                if (l <= r - c)
                    query(l, r - c, 1);

                aa = aux.h1;
                bb = aux.h2;

                aux.h1 = aux.h2 = 0;
                //cout << "query pe " << ' ' << l + c << ' ' << r << endl;

                if (l + c <= r)
                    query(l + c, r, 1);

                cc = aux.h1;
                dd = aux.h2;

                if (aa == cc && bb == dd) {
                    cout << "YES\n";
                }
                else
                    cout << "NO\n";
            //}
        }
    }

    return 0;
}