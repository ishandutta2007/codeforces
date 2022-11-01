#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define SSTR(x) dynamic_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 1e6 + 10;
const ld EPS = 1e-8;
const ll INF = 2 * 1e9 + 1;
const ll MAX = 1e9;

int dist[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    srand(time(NULL));
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    fill(dist, dist + 2 * max(n, m) + 1, INF);
    dist[n] = 0;
    queue <int> q;
    q.push(n);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (v <= max(n, m) && dist[2 * v] == INF) {
            dist[2 * v] = dist[v] + 1;
            q.push(2 * v);
        }
        if (v && dist[v - 1] == INF) {
            dist[v - 1] = dist[v] + 1;
            q.push(v - 1);
        }
    }
    cout << dist[m];
}