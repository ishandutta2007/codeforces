#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

//vector string deque break continue
#define forn(i, s, f) for (int i = (int)s; i < (int)f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pf push_front
#define pb push_back
#define pop_f pop_front
#define pop_b pop_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

template <typename T> istream& operator>>(istream& in, vector <T>& a) {for (auto& i : a) in >> i; return in;}
template <typename T> ostream& operator<<(ostream& out, vector <T>& a)  {for (auto& i : a) out << i << " "; return out;}
template <typename T, typename U> void chkmin(T& a, U b) {if (a > b) a = b;}
template <typename T, typename U> void chkmax(T& a, U b) {if (a < b) a = b;}

vector <string> parity, gr;
vector <vector <int>> col;
vector <vector <pii>> par;

#define x first
#define y second

int n, m;

bool valid(pii a) {
    return 0 <= a.fs && a.fs < n &&
           0 <= a.sc && a.sc < m;
}

int cnt, cnt_black;

vector <int> cycle;

void find_cycle(pii v, pii f) {
    //cout << "fuck:" << v.fs << " " << v.sc << ": ";
    cycle.pb(1);
    if (v.x == f.x && v.y == f.y)
        return;
    else
        find_cycle(par[v.x][v.y], f);
}

pii get(pii v) {
    pii u = v;
    if (gr[v.x][v.y] == 'L')
        u.sc--;
    if (gr[v.x][v.y] == 'R')
        u.sc++;
    if (gr[v.x][v.y] == 'U')
        u.fs--;
    if (gr[v.x][v.y] == 'D')
        u.fs++;
    return u;
}

void find_branches(pii v, pii banned, int idx) {
    idx += sz(cycle);
    idx %= sz(cycle);
    cycle[idx] &= parity[v.x][v.y];
    col[v.x][v.y] = 2;
    for (int dx : {-1, 0, 1}) {
        for (int dy : {-1, 0, 1}) {
            pii u = {v.x + dx, v.y + dy};
            if (!valid(u))
                continue;
            if (u.x == banned.x && u.y == banned.y)
                continue;
            pii t = get(u);
            if (t.x == v.x && t.y == v.y)
                find_branches(u, banned, idx - 1);
        }
    }
}

void FIND_CYCLE(pii v, pii p, pii f, int idx) {
    //cout << "fuck:" << v.fs << " " << v.sc << ": ";
    find_branches(v, p, idx);
    if (v.x == f.x && v.y == f.y)
        return;
    else
        FIND_CYCLE(get(v), v, f, idx + 1);
}


void dfs(pii v, pii p = {-1, -1}) {
    par[v.x][v.y] = p;
    col[v.x][v.y] = 1;
    pii u = get(v);
    if (!valid(u))
        return;
    if (col[u.x][u.y] == 1) {
        cycle.clear();
        find_cycle(v, u);
        cnt += sz(cycle);
        FIND_CYCLE(get(v), v, v, 0);
        for (int u : cycle)
            cnt_black += (u ^ 1);
    }
    if (col[u.x][u.y] == 0)
        dfs(u, v);
    col[v.x][v.y] = 2;
}

void solve() {
    cin >> n >> m;
    parity = gr = vector <string> (n);
    cin >> parity >> gr;
    col = vector <vector <int>> (n, vector <int> (m));
    par = vector <vector <pii>> (n, vector <pii> (m));
    cnt = cnt_black = 0;
    forn (i, 0, n)
        forn (j, 0, m)
            if (!col[i][j])
                dfs({i, j});
    cout << cnt << " " << cnt_black << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}