#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef unsigned long long ll;

const int N = 1e5;
const int INF = 2e9;
const int ALPH = 300;

int a[N];
vector <int> g[N];
int dist[N];

int main() {
    //freopen("a.in", "r", stdin);
    int n, s, t;
    cin >> n >> s >> t;
    s--, t--;
    fr(i, n) {
        cin >> a[i];
        g[i].pb(a[i] - 1);
    }
    fill(dist, dist + n, INF);
    dist[s] = 0;
    queue <int> q;
    q.push(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        fr(i, g[v].size())
            if (dist[g[v][i]] == INF) {
                dist[g[v][i]] = dist[v] + 1;
                q.push(g[v][i]);
            }
    }
    if (dist[t] == INF)
        cout << -1;
    else
        cout << dist[t];


}