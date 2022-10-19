#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 7005;
const int MAXL = 1000005;

struct query {
    int lo, hi, val;
    query(int lo, int hi, int val) : lo(lo), hi(hi), val(val) {}
    query() : lo(0), hi(0), val(0) {}
};

int N, M;
vector <query> Q[MAXN];
int exp[MAXL];
bool bio[MAXL];

void init() {
    for (int i = 1; i < MAXL; i++)
        exp[i] = exp[i / 2] + 1;
}

int ask(int a, int b) {
    vector <int> tmp;
    int l = b, r = b, sol = 0;
    for (int i = a; i <= N; i++) {
        for (int j = 0; j < Q[i].size(); j++)
            if (r >= Q[i][j].lo && l <= Q[i][j].hi && !bio[Q[i][j].val]) {
                bio[Q[i][j].val] = true;
                tmp.push_back(Q[i][j].val);
                sol++;
            }
        l += exp[l - 1];
        r += exp[r];
    }   
    for (int i = 0; i < tmp.size(); i++)
        bio[tmp[i]] = false;
    return sol;
}

void solve() {
    scanf("%d%d", &N, &M);
    while (M--) {
        int type, lvl;
        scanf("%d%d", &type, &lvl);
        if (type == 1) {
            int l, r, x;
            scanf("%d%d%d", &l, &r, &x);
            Q[lvl].push_back(query(l, r, x));
        }
        else {
            int v;
            scanf("%d", &v);
            printf("%d\n", ask(lvl, v));
        }
    }
}

int main() {
    init();
    solve();
    return 0;
}