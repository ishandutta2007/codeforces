#include <iostream>
#include <queue>
#include <utility>
#include <bitset>

#define NMAX 300005
#define inf (1ll << 62)
#define lint long long int
using namespace std;

vector <int> ans;

int n;
vector <pair <pair <int , int>, int> > graph[NMAX];

lint dist[NMAX];
lint sum[NMAX];
int muc[NMAX];

bitset <NMAX> vis;

struct elem {
    lint dist, sum;
    int y;

    elem (lint dist = 0, lint sum = 0, int y = 0): dist(dist), sum(sum), y(y) {}
};

bool operator< (const elem &a, const elem &b) {
    if (a.dist != b.dist)
        return a.dist > b.dist;
    return a.sum > b.sum;
}

priority_queue <elem> coada;

inline lint dijkstra (int s) {
    for (int i = 1; i <= n; i++) {
        dist[i] = inf;
        sum[i] = inf;
    }

    dist[s] = 0;
    sum[s] = 0;

    coada.push(elem(0, 0, s));

    int y;
    vector <pair <pair <int, int>, int> > :: iterator it;

    lint current_sum = 0;
    while (!coada.empty()) {
        y = coada.top().y;

        coada.pop();

        if (vis[y])
            continue ;

        current_sum += sum[y];

        if (y != s)
        ans.push_back(muc[y]);

        vis[y] = true;

        for (it = graph[y].begin(); it != graph[y].end(); it++) {
            if (dist[y] + it -> first.second < dist[it -> first.first]) {
                dist[it -> first.first] = dist[y] + it -> first.second;
                sum[it -> first.first] = it -> first.second;
                coada.push(elem(dist[it -> first.first], sum[it -> first.first], it -> first.first));
                muc[it -> first.first] = it->second;
            }
            else if (dist[y] + it -> first.second == dist[it -> first.first] && it -> first.second < sum[it -> first.first]) {
                sum[it -> first.first] = it -> first.second;
                coada.push(elem(dist[it -> first.first], sum[it -> first.first], it -> first.first));
                muc[it -> first.first] = it->second;
            }
        }
    }

    return current_sum;
}

int main()
{
    int m = 0;
    cin >> n >> m;

    int x, y, z;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y >> z;

        graph[x].push_back(make_pair(make_pair(y, z), i));
        graph[y].push_back(make_pair(make_pair(x, z), i));
    }

    int u = 1;
    cin >> u;

    cout << dijkstra(u) << '\n';

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
    cout << endl;

    return 0;
}