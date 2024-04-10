#include <iostream>
#include <algorithm>
#include <cstring>
#include <cassert>

using namespace std;

const int NMAX = 100005;
const int RAD = 300;

int n;
int v[NMAX];

int _left[NMAX];
int _right[NMAX];
int which_bucket[NMAX];

inline void precompute_buckets() {
    for (int i = 0; i <= n; ++ i) {
        which_bucket[i] = i / RAD;
        _right[which_bucket[i]] = i;
    }

    for (int i = 0; i <= n; i += RAD)
        _left[which_bucket[i]] = i;
}

const int QMAX = 2000005;

struct query {
    int l, r;
    int pos;

    query(int _l = 0, int _r = 0, int _pos = 0): l(_l), r(_r), pos(_pos) {}
} queries[NMAX];

bool operator<(const query &a, const query &b) {
    if (which_bucket[a.l] != which_bucket[b.l])
        return which_bucket[a.l] < which_bucket[b.l];
    return a.r < b.r;
}

long long int anss[NMAX];
int frecv[QMAX];

int main()
{
    ios_base :: sync_with_stdio(false);

    int q = 0, val = 0;
    cin >> n >> q >> val;

    for (int i = 1; i <= n; ++ i)
        cin >> v[i];
    for (int i = 1; i <= n; ++ i)
        v[i] ^= v[i - 1];

    for (int i = 1; i <= q; ++ i) {
        cin >> queries[i].l >> queries[i].r;

        -- queries[i].l;
        queries[i].pos = i;
    }

    precompute_buckets();

    sort(queries + 1, queries + q + 1);

    int j;
    for (int i = 1; i <= q; i = j + 1) {
        for (j = i; j <= q; ++ j)
            if (which_bucket[queries[i].l] != which_bucket[queries[j].l])
                break;
        -- j;

        //Avem intervalul i, j
        int p = _right[which_bucket[queries[i].l]] + 1;
        long long int ans_part = 0;

        for (int k = i; k <= j; ++ k) {
            if (queries[k].r <= _right[which_bucket[queries[i].l]]) { //Query mic
                for (int l = queries[k].l; l <= queries[k].r; ++ l) {
                    //Verifici
                    anss[queries[k].pos] += frecv[v[l] ^ val];

                    //Pui numarul
                    ++ frecv[v[l]];
                }

                //Scoti toate numerele
                for (int l = queries[k].l; l <= queries[k].r; ++ l) {
                    //Scoti numarul
                    -- frecv[v[l]];
                }
            }
            else {
                //Adaugam bucata mare
                for (; p <= queries[k].r; ++ p) {
                    //Verifici
                    ans_part += frecv[v[p] ^ val];

                    //Pui numarul
                    ++ frecv[v[p]];
                }

                anss[queries[k].pos] += ans_part;

                //Adaugam bucata mica
                for (int l = queries[k].l; l <= _right[which_bucket[queries[i].l]]; ++ l) {
                    //Verifici
                    anss[queries[k].pos] += frecv[v[l] ^ val];

                    //Pui numarul
                    ++ frecv[v[l]];
                }

                //Scoatem bucata mare
                for (int l = queries[k].l; l <= _right[which_bucket[queries[i].l]]; ++ l) {
                    //Scoti numarul
                    -- frecv[v[l]];
                }
            }
        }

        //Scoatem tot
        for (int k = 0; k <= n; ++ k)
            frecv[v[k]] = 0;
    }

    for (int i = 1; i <= q; ++ i)
        cout << anss[i] << '\n';

    return 0;
}