#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#include <cstring>
#include <queue>

using namespace std;

const int Nmax = 105, Glim = 10 * Nmax, Inf = 0x3f3f3f3f;

int A[Nmax], XX[Nmax], YY[Nmax];
vector<int> G[Glim];
map<int, int> allDivs;
int CntDivs = 0;

vector<pair<int, int>> Divs[Nmax];
int C[Glim][Glim], F[Glim][Glim], Father[Glim];

vector<pair<int, int>> getDivs(int x) {
    vector<pair<int, int>> ret;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            int k = 0;
            for (; x % i == 0; x /= i)
                ++k;
            ret.push_back({i, k});
            if (!allDivs.count(i))
                allDivs[i] = ++CntDivs;
        }
    }

    if (x > 1) {
        ret.push_back({x, 1});
        if (!allDivs.count(x))
            allDivs[x] = ++CntDivs;
    }
    return ret;
}

bool Bfs(int S, int D) {
    memset(Father, -1, sizeof Father);
    queue<int> Q;
    Q.push(S);
    while (!Q.empty()) {
        int node = Q.front();
        Q.pop();

        for (int p: G[node]) {
            if (Father[p] != -1 || C[node][p] == F[node][p]) continue;

            Father[p] = node;
            Q.push(p);
        }
    }

    return Father[D] != -1;
}

int MaxFlow(int S, int D) {
    int flow = 0;
    while (Bfs(S, D)) {
        int fmin = Inf;
        for (int i = D; i != S; i = Father[i])
            fmin = min(fmin, C[Father[i]][i] - F[Father[i]][i]);
        for (int i = D; i != S; i = Father[i]) {
            F[Father[i]][i] += fmin;
            F[i][Father[i]] -= fmin;
        }
        flow += fmin;
    }
    return flow;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    int N, M;
    scanf("%d%d", &N, &M);

    for (int i = 1; i <= N; ++i) {
        int x;
        scanf("%d", &x);
        Divs[i] = getDivs(x);
        A[i] = x;
    }

    int S = 0, D = Glim - 1;
    for (int i = 1; i <= N; ++i) {
        if (i % 2 == 1) {
            G[i].push_back(S);
            G[S].push_back(i);
        } else {
            G[i].push_back(D);
            G[D].push_back(i);
        }
    }

    for (int i = 1; i <= M; ++i) {
        scanf("%d%d", &XX[i], &YY[i]);
        if (XX[i] % 2 == 0) swap(XX[i], YY[i]);
        G[XX[i]].push_back(YY[i]);
        G[YY[i]].push_back(XX[i]);
        C[XX[i]][YY[i]] = Inf;
    }

    int ans = 0;
    for (auto dv: allDivs) {
        int cdv = dv.first;

        for (int i = 1; i <= N; ++i) {
            int k = 0;
            for (; A[i] % cdv == 0; A[i] /= cdv)
                ++k;

            if (i % 2 == 1) {
                C[S][i] = k;
                F[S][i] = F[i][S] = 0;
            } else {
                C[i][D] = k;
                F[i][D] = F[D][i] = 0;
            }
        }

        for (int i = 1; i <= M; ++i) {
            F[XX[i]][YY[i]] = F[YY[i]][XX[i]] = 0;
        }
        ans += MaxFlow(S, D);
    }
    printf("%d\n", ans);
}