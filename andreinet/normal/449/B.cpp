#include <algorithm>
#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

const int Nmax = 100005;
const long long INF = 1LL << 62;

vector< pair<int, int> > G[Nmax], G1[Nmax];
long long Dist[Nmax];
int Count[Nmax];

struct comp {
    bool operator()(const pair<long long, int> &a, const pair<long long, int> &b) const {
        return a.first > b.first;
    }
};

void Dijkstra(const int N, const int Source)
{
    for (int i = 1; i <= N; i++)
        Dist[i] = INF;

    priority_queue< pair<long long, int>, vector< pair<long long, int> >, comp> H;
    Dist[Source] = 0;
    H.push(make_pair(0LL, Source));

    while (!H.empty())
    {
        const int node = H.top().second;
        const long long dist = H.top().first;
        H.pop();

        if (dist > Dist[node]) continue;

        for (const auto p: G[node])
        {
            if (Dist[p.first] > dist + p.second)
            {
                Dist[p.first] = dist + p.second;
                H.push(make_pair(Dist[p.first], p.first));
            }
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif

    ios :: sync_with_stdio(false);

    int N, M, K;
    cin >> N >> M >> K;

    while (M--)
    {
        int x, y, z;
        cin >> x >> y >> z;

        G[x].push_back(make_pair(y, z));
        G[y].push_back(make_pair(x, z));
    }

    for (int i = 1; i <= N; i++) G1[i] = G[i];

    while (K--)
    {
        int x, y;
        cin >> x >> y;

        G[1].push_back(make_pair(x, y));
        G[x].push_back(make_pair(1, y));
        Count[x]++;
    }

    Dijkstra(N, 1);

    int Ans = 0;
    for (int i = 2; i <= N; i++)
    {
        if (!Count[i]) continue;

        bool ok = 0;

        for (const auto p: G1[i])
        {
            if (Dist[p.first] + p.second == Dist[i])
            {
                ok = 1;
                break;
            }
        }

        Ans += Count[i] - 1 + ok;
    }

    cout << Ans << '\n';
}