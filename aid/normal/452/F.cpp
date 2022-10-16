#include <iostream>

using namespace std;

struct Node {
    int h[2], rh[2];
};

const int MAXN = 300 * 1000 + 5,
    MOD[2] = {1012741521, 1036481731}, P[2] = {1333331, 1777777};
int p[MAXN], ppow[MAXN][2];
Node st[4 * MAXN];

void buildst(int v, int tl, int tr) {
    if(tl == tr - 1) {
        for(int i = 0; i < 2; i++) {
            st[v].h[i] = 1;
            st[v].rh[i] = 1;
        }
        return;
    }
    int tm = (tl + tr) / 2;
    buildst(2 * v, tl, tm);
    buildst(2 * v + 1, tm, tr);
    for(int i = 0; i < 2; i++) {
        st[v].h[i] = ((long long)st[2 * v].h[i] * ppow[tr - tm][i] +
                      st[2 * v + 1].h[i]) % MOD[i];
        st[v].rh[i] = ((long long)st[2 * v + 1].rh[i] * ppow[tm - tl][i] +
                      st[2 * v ].rh[i]) % MOD[i];
    }
}

pair<int, int> getHash(int v, int tl, int tr, int l, int r, bool rev) {
    if(tl == l && tr == r)
        return rev? make_pair(st[v].rh[0], st[v].rh[1]) :
            make_pair(st[v].h[0], st[v].h[1]);
    int tm = (tl + tr) / 2;
    if(r <= tm)
        return getHash(2 * v, tl, tm, l, r, rev);
    if(l >= tm)
        return getHash(2 * v + 1, tm, tr, l, r, rev);
    pair<int, int> pl = getHash(2 * v, tl, tm, l, tm, rev),
        pr = getHash(2 * v + 1, tm, tr, tm, r, rev);
    if(rev)
        return make_pair(((long long)pr.first * ppow[tm - l][0] +
                          pl.first) % MOD[0],
                         ((long long)pr.second * ppow[tm - l][1] +
                          pl.second) % MOD[1]);
    return make_pair(((long long)pl.first * ppow[r - tm][0] +
                      pr.first) % MOD[0],
                     ((long long)pl.second * ppow[r - tm][1] +
                      pr.second) % MOD[1]);
}

void update(int v, int tl, int tr, int pos, int val) {
    if(tl == tr - 1) {
        for(int i = 0; i < 2; i++) {
            st[v].h[i] = val;
            st[v].rh[i] = val;
        }
        return;
    }
    int tm = (tl + tr) / 2;
    if(pos < tm)
        update(2 * v, tl, tm, pos, val);
    else
        update(2 * v + 1, tm, tr, pos, val);
    for(int i = 0; i < 2; i++) {
        st[v].h[i] = ((long long)st[2 * v].h[i] * ppow[tr - tm][i] +
                      st[2 * v + 1].h[i]) % MOD[i];
        st[v].rh[i] = ((long long)st[2 * v + 1].rh[i] * ppow[tm - tl][i] +
                      st[2 * v ].rh[i]) % MOD[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for(int i = 0; i < 2; i++) {
        ppow[0][i] = 1;
        for(int j = 1; j < MAXN; j++)
            ppow[j][i] = (long long)ppow[j - 1][i] * P[i] % MOD[i];
    }
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }
    buildst(1, 0, n);
    for(int i = 0; i < n; i++) {
        int d = min(p[i], n - p[i] - 1);
        if(d) {
            pair<int, int> l = getHash(1, 0, n, p[i] - d, p[i], false),
                r = getHash(1, 0, n, p[i] + 1, p[i] + d + 1, true);
            if(l != r) {
                cout << "YES\n";
                return 0;
            }
        }
        update(1, 0, n, p[i], 2);
    }
    cout << "NO\n";
    return 0;
}