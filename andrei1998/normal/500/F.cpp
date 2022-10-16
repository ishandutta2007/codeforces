#include <iostream>
#include <vector>

using namespace std;

struct item {
    int w, p;

    item (int w = 0, int p = 0): w(w), p(p) {}
};

int n = 0, p = 0;
vector <item> items[10005];

struct query {
    int st;
    int w, pos;

    query (int st = 0, int w = 0, int pos = 0): st(st), w(w), pos(pos) {}
};

vector <query> queries[10005];
int ans[20005];

int rucsac_st[4005][4005];
int rucsac_dr[4005][4005];
int cine_st[10005];
int cine_dr[10005];

void _do (int mijl) {
    //Calculam rucsacul la stanga
    int pos_st = 0;
    for (int i = mijl; i >= mijl - p + 1 && i >= 1; i--) {
        for (auto it: items[i]) {
            pos_st ++;
            for (int j = 0; j <= 4000; j++)
                rucsac_st[pos_st][j] = max(rucsac_st[pos_st - 1][j], j >= it.w ? rucsac_st[pos_st - 1][j - it.w] + it.p : 0);
            for (int j = 1; j <= 4000; j++)
                rucsac_st[pos_st][j] = max(rucsac_st[pos_st][j - 1], rucsac_st[pos_st][j]);
        }

        cine_st[i] = pos_st;
    }

    //Calculam rucsacul la dreapta
    int pos_dr = 0;

    cine_dr[mijl] = 0;
    for (int i = mijl + 1; i <= mijl + p - 1 && i <= 10000; i++) {
        for (auto it: items[i]) {
            pos_dr ++;
            for (int j = 0; j <= 4000; j++)
                rucsac_dr[pos_dr][j] = max(rucsac_dr[pos_dr - 1][j], j >= it.w ? rucsac_dr[pos_dr - 1][j - it.w] + it.p : 0);
            for (int j = 1; j <= 4000; j++)
                rucsac_dr[pos_dr][j] = max(rucsac_dr[pos_dr][j - 1], rucsac_dr[pos_dr][j]);
        }

        cine_dr[i] = pos_dr;
    }

    //Rezolvam toate query-urile care trec prin mijloc
    int lst, ldr;
    for (int i = mijl; i <= mijl + p - 1 && i <= 10000; i++)
        while (!queries[i].empty() && queries[i].back().st <= mijl) {
            lst = cine_st[queries[i].back().st];
            ldr = cine_dr[i];

            for (int j = 0; j <= queries[i].back().w; j++)
                if (rucsac_st[lst][j] + rucsac_dr[ldr][queries[i].back().w - j] > ans[queries[i].back().pos])
                    ans[queries[i].back().pos] = rucsac_st[lst][j] + rucsac_dr[ldr][queries[i].back().w - j];
            queries[i].pop_back();
        }
}

void solve () {
    for (int mijl = 1; mijl <= 10000; mijl += p)
        _do(mijl);
    _do(10000);
}

int main()
{
    cin >> n >> p;

    item aux;
    int t;

    while (n--) {
        cin >> aux.w >> aux.p >> t;
        items[t].push_back(aux);
    }

    int q = 0;
    cin >> q;

    int w;
    for (int i = 1; i <= q; i++) {
        cin >> t >> w;

        if (max(1, t - p + 1) <= min(t, 10000)) //Caz particular
            queries[min(t, 10000)].push_back(query(max(1, t - p + 1), w, i));
    }

    solve();

    for (int i = 1; i <= q; i++)
        cout << ans[i] << '\n';
    return 0;
}