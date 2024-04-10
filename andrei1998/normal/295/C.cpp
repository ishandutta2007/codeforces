#include <iostream>
#include <queue>

using namespace std;

const int NMAX = 55;
const int KMAX = 105;
const int mod = 1000000007;

int n, k;

struct state {
    int unu_st, doi_st;
    int unu_dr, doi_dr;
    bool boat;

    state(int _unu_st = 0, int _doi_st = 0, int _unu_dr = 0, int _doi_dr = 0, bool _boat = false): unu_st(_unu_st), doi_st(_doi_st), unu_dr(_unu_dr), doi_dr(_doi_dr), boat(_boat) {}
};

int dist[55][55][2];
int sols[55][55][2];

queue <state> coada;

inline void upd(int &dist, int val, int &sols, int cate) {
    if (!dist) {
        dist = val;
        sols = cate;
    }
    else if (dist == val) {
        sols += cate;
        if (sols >= mod)
            sols -= mod;
    }
}

int comb[55][55];

int main()
{
    cin >> n >> k;

    for (int i = 0; i <= n + 1; ++ i) {
        comb[i][0] = 1;
        for (int j = 1; j <= i; ++ j) {
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
            if (comb[i][j] >= mod)
                comb[i][j] -= mod;
        }
    }

    k /= 50;

    int unu = 0, doi = 0;

    int val;
    for (int i = 1; i <= n; ++ i) {
        cin >> val;
        val /= 50;

        if (val == 1)
            ++ unu;
        else
            ++ doi;
    }

    dist[unu][doi][0] = 1;
    sols[unu][doi][0] = 1;

    coada.push(state(unu, doi));

    state y;
    while (!coada.empty()) {
        y = coada.front();
        coada.pop();

        int dst = dist[y.unu_st][y.doi_st][y.boat];
        int sol = sols[y.unu_st][y.doi_st][y.boat];

        if (y.boat == 0) {
            for (int i = 0; i <= y.unu_st; ++ i)
                for (int j = 0; j <= y.doi_st && i + 2 * j <= k; ++ j)
                    if (i + j) {
                        if (!dist[y.unu_st - i][y.doi_st - j][y.boat ^ 1])
                            coada.push(state(y.unu_st - i, y.doi_st - j, y.unu_dr + i, y.doi_dr + j, y.boat ^ 1));
                        upd(dist[y.unu_st - i][y.doi_st - j][y.boat ^ 1], 1 + dst, sols[y.unu_st - i][y.doi_st - j][y.boat ^ 1], ((1ll * sol * comb[y.unu_st][i]) % mod * comb[y.doi_st][j]) % mod);
                    }
        }
        else {
            for (int i = 0; i <= y.unu_dr; ++ i)
                for (int j = 0; j <= y.doi_dr && i + 2 * j <= k; ++ j)
                    if (i + j) {
                        if (!dist[y.unu_st + i][y.doi_st + j][y.boat ^ 1])
                            coada.push(state(y.unu_st + i, y.doi_st + j, y.unu_dr - i, y.doi_dr - j, y.boat ^ 1));
                        upd(dist[y.unu_st + i][y.doi_st + j][y.boat ^ 1], 1 + dst, sols[y.unu_st + i][y.doi_st + j][y.boat ^ 1], ((1ll * sol * comb[y.unu_dr][i]) % mod * comb[y.doi_dr][j]) % mod);
                    }

        }
    }

    cout << dist[0][0][1] - 1 << '\n';
    cout << sols[0][0][1] << '\n';
    return 0;
}