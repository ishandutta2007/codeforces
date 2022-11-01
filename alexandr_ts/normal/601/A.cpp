#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair <long long, long long> pr;
typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ll INF = 2e9;
const ll N = 1e3 + 2;
const ld EPS = 1e-8;

vector <int> g[N], g2[N];

int dist[N], dist2[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    int u, v;
    fr(i, m) {
        cin >> v >> u;
        g[--v].pb(--u);
        g[u].pb(v);
    }
    fr(i, n)
        sort(g[i].begin(), g[i].end());
    int cur = 0;
    fr(i, n) {
        cur = 0;
        fr(j, n)
            if (cur < g[i].size() && j == g[i][cur])
                cur++;
            else if (i != j) g2[i].pb(j);
    }

//    fr(i, n) {
//        fr(j, g2[i].size())
//            cout << g2[i][j] << " ";cout << endl;}

    fill(dist, dist + n + 1, INF);
    fill(dist2, dist2 + n + 1, INF);
    queue <int> q;
    q.push(0);
    dist[0] = dist2[0] = 0;
    while (q.size() > 0) {
        int t = q.front();
        q.pop();
        fr(i, g[t].size())
            if (dist[g[t][i]] == INF)
                q.push(g[t][i]), dist[g[t][i]] = dist[t] + 1;
    }
    //q.clear();
    queue <int> q2;
    q2.push(0);
    while (q2.size() > 0) {
        int t = q2.front();
        q2.pop();
        fr(i, g2[t].size())
            if (dist2[g2[t][i]] == INF)
                q2.push(g2[t][i]), dist2[g2[t][i]] = dist2[t] + 1;
    }
    if (dist[n - 1] == INF || dist2[n - 1] == INF)
        cout << -1;
    else cout << max(dist[n - 1], dist2[n - 1]);

}