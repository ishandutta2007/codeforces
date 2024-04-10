#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
#define DBG(v) cerr << #v << " = " << (v) << endl;


const int MxN = (int) 1e4;
const int MxG = (int) 1e3;
int dist[MxN + 3][MxG + 3];
int a[MxN + 9];
vector<pair<int, pair<int, int>>> q[MxN + 9];
int N, G, R;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    {
        int len;
        cin >> len >> N;
        for (int i = 0; i < N; ++i)
            cin >> a[i];
        assert(len == *max_element(a, a + N));
    }
    cin >> G >> R;

    sort(a, a + N);
    N = unique(a, a + N) - a;

    const int Inf = N * (R + G) + 1;

    for (int i = 0; i < N; ++i)
        for (int k = 0; k <= G; ++k)
            dist[i][k] = Inf;


    q[0].emplace_back(dist[0][G] = 0, pair<int, int>{0, G});

    int ans = Inf;
    for (int qIdx = 0; qIdx <= ans/(R + G); ++qIdx) {

        while (!q[qIdx].empty()) {
            const int du = q[qIdx].back().first;
            const pair<int, int> u = q[qIdx]
                    .back().second;

            if (u.first == N - 1) {
                ans = min(ans, du);
            }
            q[qIdx].pop_back();
            if (du != dist[u.first][u.second])
                continue;

            auto relax = [&](const int v1, const int v2, const int w) {
                if (dist[v1][v2] > dist[u.first][u.second] + w) {
                    dist[v1][v2] = dist[u.first][u.second] + w;
                    q[dist[v1][v2] / (R + G)].emplace_back(dist[v1][v2], pair<int, int>{v1, v2});
                }
            };

            if (!u.second)
                relax(u.first, G, R);
            else {
                if (u.first > 0 && a[u.first] - a[u.first - 1] <= u.second)
                    relax(u.first - 1, u.second - (a[u.first] - a[u.first - 1]), a[u.first] - a[u.first - 1]);
                if (u.first + 1 < N && a[u.first + 1] - a[u.first] <= u.second)
                    relax(u.first + 1, u.second - (a[u.first + 1] - a[u.first]), a[u.first + 1] - a[u.first]);
            }
        }
    }

    cout << (ans >= Inf ? -1:ans);
    return 0;
}