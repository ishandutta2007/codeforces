#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 200011

int n, m, i, k, j, x, S;
vector<int> list[maxN];
vector<int> order;
int id[maxN];
bool us[maxN];

bool can[maxN][2];
int prov[maxN][2];
queue< pair<int, int> > Q;

int win, draw;
vector<int> nodes;

void dfs(int node) {
    us[node] = true;
    for (auto to : list[node])
        if (!us[to])
            dfs(to);
    order.pb(node);
    id[node] = order.size();
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++) {
        scanf("%d", &k);
        for (j = 1; j <= k; j++) {
            scanf("%d", &x);
            list[i].pb(x);
        }
    }

    scanf("%d", &S);
    dfs(S);

    can[S][1] = true;
    Q.push(mp(S, 1));
    while (!Q.empty()) {
        int node = Q.front().first;
        int tp = Q.front().second;
        Q.pop();

        for (auto to : list[node]) {
            if (can[to][tp ^ 1] == false) {
                can[to][tp ^ 1] = true;
                prov[to][tp ^ 1] = node;
                Q.push(mp(to, tp ^ 1));
            }
        }
    }

    for (auto node : order) {
        if (list[node].empty() && can[node][0]) {
            win = node;
            break;
        }

        for (auto to : list[node])
            if (id[to] > id[node])
                draw = 1;
    }

    if (win == 0 && draw == 0) {
        cout << "Lose";
        return 0;
    }


    if (win == 0) {
        cout << "Draw";
        return 0;
    }

    int tp = 0;
    while (prov[win][tp] != 0) {
        nodes.pb(win);
        win = prov[win][tp];
        tp ^= 1;
    }
    nodes.pb(S);
    reverse(nodes.begin(), nodes.end());

    cout << "Win\n";
    for (auto e : nodes) cout << e << ' ';




    return 0;
}