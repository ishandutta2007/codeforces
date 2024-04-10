#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double

const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;

vector<int> usd, with;
vector<vector<int>> g;

int dfs(int v) {
    if (usd[v]) return 0;
    usd[v] = 1;
    for (auto &to : g[v]) {
        if (with[to] == -1 || dfs(with[to])) {
            with[to] = v;
            return 1;
        }
    }
    return 0;
}

bool inter(const pair<pii, pii> &segx, const pair<pii, pii> &segy) {
    return segx.fi.fi > segy.fi.fi && segx.fi.fi < segy.se.fi
    && segy.fi.se > segx.fi.se && segy.fi.se < segx.se.se;
}

vector<vector<int>> g1;

void dfs1(int v) {
    usd[v] = 1;
    for (auto &to : g1[v]) {
        if (!usd[to]) dfs1(to);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    map<int, vector<int>> samex, samey;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        samex[x].pb(y);
        samey[y].pb(x);
    }
    map<pair<pii, pii>, int> idx;
    map<pair<pii, pii>, int> idy;
    int curidx = 0, curidy = 0;
    for (auto &c : samex) {
        sort(all(c.se));
        c.se.resize(unique(all(c.se)) - c.se.begin());
        for (int i = 0; i + 1 < (int)c.se.size(); i++) {
            idx[{{c.fi, c.se[i]}, {c.fi, c.se[i + 1]}}] = curidx++;
        }
    }
    for (auto &c : samey) {
        sort(all(c.se));
        c.se.resize(unique(all(c.se)) - c.se.begin());
        for (int i = 0; i + 1 < (int)c.se.size(); i++) {
            idy[{{c.se[i], c.fi}, {c.se[i + 1], c.fi}}] = curidy++;
        }
    }
    g.resize(curidx);
    with.assign(curidy, -1);
    for (auto &segx : idx) {
        for (auto &segy : idy) {
            if (inter(segx.fi, segy.fi)) {
                g[segx.se].pb(segy.se);
            }
        }
    }
    for (int i = 0; i < curidx; i++) {
        usd.assign(curidx, 0);
        dfs(i);
    }
    vector<int> in(curidx);
    for (auto &c : with) {
        if (c != -1) in[c] = 1;
    }
    g1.resize(curidx + curidy);
    for (int i = 0; i < curidx; i++) {
        for (auto &to : g[i]) {
            if (with[to] == i) g1[curidx + to].pb(i);
            else
                g1[i].pb(curidx + to);
        }
    }
    usd.assign(curidx + curidy, 0);
    for (int i = 0; i < curidx; i++) {
        if (!in[i]) dfs1(i);
    }
    vector<int> badidx(curidx), badidy(curidy);
    for (int i = 0; i < curidx; i++) {
        if (!usd[i]) {
            badidx[i] = 1;
        }
    }
    for (int i = 0; i < curidy; i++) {
        if (usd[i + curidx]) {
            badidy[i] = 1;
        }
    }
    vector<pair<pii, pii>> hor, ver;
    curidx = curidy = 0;
    for (auto &c : samex) {
        for (int i = 0; i < (int)c.se.size(); i++) {
            int j = i;
            while (j + 1 < (int)c.se.size()) {
                if (!badidx[curidx + j]) j++;
                else
                    break;
            }
            ver.pb(make_pair(c.fi, c.se[i]), make_pair(c.fi, c.se[j]));
            i = j;
        }
        curidx += (int)c.se.size() - 1;
    }
    for (auto &c : samey) {
        for (int i = 0; i < (int)c.se.size(); i++) {
            int j = i;
            while (j + 1 < (int)c.se.size()) {
                if (!badidy[curidy + j]) j++;
                else
                    break;
            }
            hor.pb(make_pair(c.se[i], c.fi), make_pair(c.se[j], c.fi));
            i = j;
        }
        curidy += (int)c.se.size() - 1;
    }
    cout << hor.size() << "\n";
    for (auto &c : hor) cout << c.fi.fi << " " << c.fi.se << " " << c.se.fi << " " << c.se.se << "\n";
    cout << ver.size() << "\n";
    for (auto &c : ver) cout << c.fi.fi << " " << c.fi.se << " " << c.se.fi << " " << c.se.se << "\n";
    return 0;
}