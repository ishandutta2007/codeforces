#include<bits/stdc++.h>

using namespace std;

int const maxn = 1e7 + 5;
vector < int > Q[maxn];
int imin[maxn], cur = 2, psh[maxn], nxtl[maxn], nxtr[maxn];
set < int > ans;

inline void push(int i) {
    if (nxtl[i] == 0) {
        nxtl[i] = cur++, nxtr[i] = cur++;
    }
    psh[nxtl[i]] += psh[i], psh[nxtr[i]] += psh[i];
    imin[i] += psh[i];
    psh[i] = 0;
}

int dfs(int i, int l, int r, int x) {
    push(i);
    for (auto key : Q[i]) ans.insert(key);
    if (r - l == 1) {
        return l;
    }
    int m = (r + l) / 2;
    if (imin[nxtl[i]] + psh[nxtl[i]] == x) return dfs(nxtl[i], l, m, x);
    assert(imin[nxtr[i]] + psh[nxtr[i]] == x);
    return dfs(nxtr[i], m, r, x);
}

void update(int i, int l, int r, int lq, int rq, int x) {
    push(i);
    if (lq >= r || l >= rq) return;
    if (lq <= l && r <= rq) {
        psh[i]++;
        Q[i].push_back(x);
        push(i);
        return;
    }
    int m = (r + l) / 2;
    update(nxtl[i], l, m, lq, rq, x);
    update(nxtr[i], m, r, lq, rq, x);
    imin[i] = min(imin[nxtl[i]], imin[nxtr[i]]);
}

inline void add(int l, int r, int m, int i) {
    //cout << l << " " << r << endl;
    assert(l <= r);
    if (r < m / 2) {
        update(1, 0, m / 2, l, r + 1, i);
    }
    else {
        update(1, 0, m / 2, l, m / 2, i);
        update(1, 0, m / 2, 0, r - m / 2 + 1, i);
    }
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, h, m, k, H, M;
    cin >> n >> h >> m >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> H >> M;
        int lef = M + 1, righ = M + k - 1;
        if (lef <= righ) {
            while (lef >= m / 2) {
                lef -= m / 2;
                righ -= m / 2;
            }
            add(lef, righ, m, i);
        }
    }
    cout << imin[1] << " " << dfs(1, 0, m / 2, imin[1]) << '\n';
    for (auto key : ans) cout << key << " ";
    return 0;
}