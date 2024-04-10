#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 3e3 + 1;
const ld EPS = 1e-9;
const ll INF = 2e9 + 10;
const ll MOD = 1e9 + 7;

vector <int> g[N];
int dist[N];
int dist2[N][N];
vector <pair <int, int> > from[N], to[N];

int main() {
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("a.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    fr(i, m) {
        int v1, v2;
        cin >> v1 >> v2;
        g[--v1].pb(--v2);
    }

    fr(i, n) {
        fill(dist, dist + n, INF);
        dist[i] = 0;
        queue <int> q;
        q.push(i);
        while (q.size()) {
            int v = q.front();
            q.pop();
            fr(j, g[v].size())
                if (dist[g[v][j]] == INF) {
                    dist[g[v][j]] = dist[v] + 1;
                    q.push(g[v][j]);
                }
        }
        fr(j, n)
            dist2[i][j] = dist[j];
//        fr(j, n)
//            cout << dist[j] << " ";
//        cout << i << endl;
        fr(j, n) {
            if (j == i || dist[j] == INF) continue;
            from[i].pb(mp(dist[j], j));
            sort(from[i].begin(), from[i].end());
            reverse(from[i].begin(), from[i].end());
            from[i].resize(min((int)from[i].size(), 3));
        }
        fr(j, n) {
            if (j == i || dist[j] == INF) continue;
            to[j].pb(mp(dist[j], i));
            sort(to[j].begin(), to[j].end());
            reverse(to[j].begin(), to[j].end());
            to[j].resize(min((int)to[j].size(), 3));
        }
    }

    vector <int> ans, cur;
    int answer = -INF;

    fr(v2, n)
        fr(v3, n)
            if (v2 != v3 && dist2[v2][v3] != INF) {
                fr(i1, to[v2].size()) {
                    int v1 = to[v2][i1].second;
                    if (v1 != v3)
                        fr(i4, from[v3].size()) {
                            int v4 = from[v3][i4].second;
                            if (v4 != v2 && v4 != v3 && v4 != v1) {
                                if (dist2[v2][v3] + to[v2][i1].first + from[v3][i4].first > answer) {
                                    answer = dist2[v2][v3] + to[v2][i1].first + from[v3][i4].first;
                                    //cout << to[v2][i1].first << " " << v2 << " " << to[v2][i1].second << endl;
                                    ans.clear();
                                    ans.pb(v1), ans.pb(v2), ans.pb(v3), ans.pb(v4);
                                }
                            }
                        }
                }
            }
    //cout << answer << endl;
    fr(i, ans.size())
        cout << ans[i] + 1 << " ";
}