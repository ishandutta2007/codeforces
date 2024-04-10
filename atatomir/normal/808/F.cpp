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

#define maxN 111
#define def 250011
#define inf 1000000000

struct card {
    int power, cost, level;

    bool operator<(const card& who)const {
        return level < who.level;
    }
};

int n, k, i;
card Card[maxN];

int S, D;
vector<int> list[maxN];
int F[maxN][maxN];
int C[maxN][maxN];
int prov[maxN];
queue<int> Q;

bool pr[def + 11];
int total_flow;

void pre() {
    ll i, j;

    pr[1] = true;
    for (i = 2; i <= def; i++) {
        if (pr[i]) continue;
        for (j = i * i; j <= def; j += i)
            pr[j] = true;
    }
}

void add_edge(int x, int y, int cap) {
    list[x].pb(y);
    list[y].pb(x);
    C[x][y] = cap;
}

bool bellman() {
    memset(prov, 0, sizeof(prov));
    prov[S] = S;
    Q.push(S);

    while (!Q.empty()) {
        int node = Q.front(); Q.pop();
        if (node == D) continue;

        for (auto to : list[node]) {
            if (prov[to]) continue;
            if (C[node][to] == F[node][to]) continue;

            prov[to] = node;
            Q.push(to);
        }
    }

    if (!prov[D]) return false;

    for (auto to : list[D]) {
        if (!prov[to]) continue;
        if (C[to][D] == F[to][D]) continue;

        prov[D] = to;
        int flow = inf;

        for (int node = D; node != S; node = prov[node])
            flow = min(flow, C[prov[node]][node] - F[prov[node]][node]);

        for (int node = D; node != S; node = prov[node]) {
            F[prov[node]][node] += flow;
            F[node][prov[node]] -= flow;
        }

        total_flow += flow;
    }


    return true;
}

bool check(int last) {
    int i, j;
    int id = -1;
    int total = 0;

    for (i = 1; i <= last; i++) {
        if (Card[i].cost != 1) continue;
        if (id == -1) id = i;
        if (Card[id].power < Card[i].power) id = i;
    }

    S = last + 1;
    D = last + 2;
    memset(F, 0, sizeof(F));
    memset(C, 0, sizeof(C));
    for (i = 1; i <= D; i++) list[i].clear();

    for (i = 1; i <= last; i++) {
        if (Card[i].cost == 1 && id != i) continue;
        total += Card[i].power;

        if (Card[i].cost % 2 == 0) {
            add_edge(S, i, Card[i].power);
        } else {
            add_edge(i, D, Card[i].power);
        }
    }

    for (i = 1; i <= last; i++) {
        if (Card[i].cost % 2 == 1) continue;
        for (j = 1; j <= last; j++) {
            if (Card[j].cost % 2 == 0) continue;
            if (Card[j].cost == 1 && id != j) continue;
            if (pr[Card[i].cost + Card[j].cost]) continue;

            add_edge(i, j, inf);
        }
    }

    total_flow = 0;
    while (bellman());

    total -= total_flow;
    return total >= k;
}

int main()
{
    //freopen("test.in","r",stdin);

    cin >> n >> k;
    for (i = 1; i <= n; i++)
        cin >> Card[i].power >> Card[i].cost >> Card[i].level;

    sort(Card + 1, Card + n + 1);
    pre();

    int ans = 0;
    for (int step = 1 << 10; step > 0; step >>= 1)
        if (ans + step <= n)
            if (!check(ans + step))
                ans += step;

    ans++;
    if (ans > n)
        cout << -1;
    else
        cout << Card[ans].level;


    return 0;
}