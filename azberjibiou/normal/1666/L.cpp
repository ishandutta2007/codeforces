#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<int> v[200009], st, ans[2];
vector<pair<int, int> > rv[200009];

int gn[200009], cn[200009], pn[200009], cc = 0, gc = 0;
bool sf[200009], vs[200009];

int dfs(int n)
{
    cc++; cn[n] = cc;
    st.push_back(n);
    int r = cn[n];
    for (int i = 0; i < v[n].size(); i++) {
        int tn = v[n][i];
        if (!cn[tn]) r = min(r, dfs(tn));
        else if (!gn[tn]) r = min(r, cn[tn]);
    }
    if (r == cn[n]) {
        gc++;
        while (true) {
            int hn = st.back(); st.pop_back();
            gn[hn] = gc;
            if (hn == n) break;
        }
    }
    return r;
}

int s0 = 0, s1 = 0, t = 0;

void dp(int n)
{
    vs[n] = true;
    for (int i = 0; i < rv[n].size(); i++) {
        int tn = rv[n][i].first;
        if (!vs[tn]) dp(tn);
        if (t) return;
        if (pn[tn]) {
            if (pn[n] && pn[n] != pn[tn]) {
                s0 = pn[n]; s1 = pn[tn]; 
                t = rv[n][i].second;
                break;
            }
            pn[n] = pn[tn];
        }
    }
}

bool ff = false;

void dfs1(int n, int tg, int pi)
{
    vs[n] = true;
    if (n == tg) {
        ans[pi].push_back(n);
        ff = true;
        return;
    }
    for (int i = 0; i < v[n].size(); i++) {
        int tn = v[n][i];
        if (!vs[tn]) dfs1(tn, tg, pi);
        if (ff) {
            ans[pi].push_back(n);
            return;
        }
    }
}

queue<int> q;
int pr[200009];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, s; cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        if (a == s) sf[b] = true;
        else if (b != s) v[a].push_back(b);
    }
    for (int i = 1; i <= n; i++)
        if (!cn[i])
            dfs(i);
    for (int i = 1; i <= n; i++) {
        if (!sf[i]) continue;
        if (pn[gn[i]]) {
            s0 = pn[gn[i]]; s1 = i;
            t = i;
        }
        pn[gn[i]] = i;
    }
    if (!t) {
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < v[i].size(); j++) {
                int tn = v[i][j];
                if (gn[i] != gn[tn])
                    rv[gn[tn]].push_back(make_pair(gn[i], tn));
            }
        }
        for (int i = 1; i <= gc; i++)
            if (!vs[i]) {
                dp(i);
                if (t) break;
            }
    }

    if (!t) {
        cout << "Impossible" << '\n';
        return 0;
    }

    q.push(s0);
    for (int i = 1; i <= n; i++) pr[i] = -1;
    pr[s0] = 0;
    while (!q.empty()) {
        int hn = q.front(); q.pop();
        for (int i = 0; i < v[hn].size(); i++) {
            int tn = v[hn][i];
            if (pr[tn] == -1) {
                pr[tn] = hn;
                q.push(tn);
            }
        }
    }
    int pp = t;
    while (pp) {
        ans[0].push_back(pp);
        pp = pr[pp];
    }
    ans[0].push_back(s); reverse(ans[0].begin(), ans[0].end());

    q.push(s1);
    for (int i = 1; i <= n; i++) pr[i] = -1;
    pr[s1] = 0;
    while (!q.empty()) {
        int hn = q.front(); q.pop();
        for (int i = 0; i < v[hn].size(); i++) {
            int tn = v[hn][i];
            if (pr[tn] == -1) {
                pr[tn] = hn;
                q.push(tn);
            }
        }
    }
    pp = t;
    while (pp) {
        ans[1].push_back(pp);
        pp = pr[pp];
    }
    ans[1].push_back(s); reverse(ans[1].begin(), ans[1].end());

    cout << "Possible" << '\n';
    cout << ans[0].size() << '\n';
    for (int i = 0; i < ans[0].size(); i++)
        cout << ans[0][i] << " ";
    cout << '\n';

    cout << ans[1].size() << '\n';
    for (int i = 0; i < ans[1].size(); i++)
        cout << ans[1][i] << " ";
    cout << '\n';
    return 0;
}