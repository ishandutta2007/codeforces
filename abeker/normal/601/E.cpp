#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <cassert>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 30005;
const int offset = 1 << 15;
const int P = (int)1e7 + 19;
const int MOD = (int)1e9 + 7;

int N, K, Q;
vector <pii> V;
int b[2 * offset], e[2 * offset];
bool f[2 * offset];
vector <int> ex[2 * offset];
stack < vector <int> > dp;

void input(int timer) {
    int v, w;
    scanf("%d%d", &v, &w);
    b[V.size()] = timer;
    V.push_back(pii(v, w));
}

void load() {
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i++)  
        input(0);
    scanf("%d", &Q);
    for (int i = 0; i < N + Q; i++)
        e[i] = MAXN;
    for (int i = 0; i < Q; i++) {
        int type;
        scanf("%d", &type);
        if (type == 1) input(i);
        else if (type == 2) {
            int x;
            scanf("%d", &x);
            e[--x] = i;
        }
        else f[i] = true; 
    }
}

inline void add(int &x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

inline int mul(int x, int y) {
    return (long long)x * y % MOD;
}

void update(int x, int lo, int hi, int from, int to, int val) {
    if (lo >= to || hi <= from) return;
    if (lo >= from && hi <= to) {
        ex[x].push_back(val);
        return;
    }
    int mid = (lo + hi) / 2;
    update(2 * x, lo, mid, from, to, val);
    update(2 * x + 1, mid, hi, from, to, val);
}

void dfs(int x) {
    for (int i = 0; i < ex[x].size(); i++) {
        vector <int> tmp(K + 1);
        int idx = ex[x][i];
        for (int j = 0; j <= K; j++) {
            tmp[j] = dp.top()[j];
            if (j >= V[idx].second)
                tmp[j] = max(tmp[j], dp.top()[j - V[idx].second] + V[idx].first);
        }
        dp.push(tmp);
    }

    if (x < offset) {
        dfs(2 * x);
        dfs(2 * x + 1);
    }
    else if (f[x - offset]) {
        int sol = 0, pot = 1;
        for (int i = 1; i <= K; i++) {
            add(sol, mul(dp.top()[i], pot));
            pot = mul(pot, P);
        }
        printf("%d\n", sol);
    }
    
    for (int i = 0; i < ex[x].size(); i++)  
        dp.pop();
}

void solve() {
    for (int i = 0; i < V.size(); i++)
        update(1, 0, offset, b[i], e[i], i);
    
    dp.push(vector <int> (K + 1, 0));
    dfs(1);
}

int main() {
    load();
    solve();
    return 0;
}