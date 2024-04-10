#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 4e5;
const int INF = 2e9 + 1;

ll a[N];
ll dist[N];
vector <int> g[N];
queue <int> q;

int main() {
    //freopen("input.txt", "r", stdin);
    int n, t;
    cin >> n;
    fill(dist, dist + n, INF);
    fr(i, n) {
        cin >> t;
        if (t != -1)
            g[t - 1].pb(i);
        else {
            dist[i] = 0;
            q.push(i);
        }
    }
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        fr(i, g[v].size())
            if (dist[g[v][i]] == INF) {
                dist[g[v][i]] = dist[v] + 1;
                q.push(g[v][i]);
            }
    }
    cout << 1 + *max_element(dist, dist + n);

}