#include <bits/stdc++.h>

using namespace std;

typedef long long int lint;
const int NMAX = 2 * 100000 + 5;

int p[NMAX];
int w[NMAX];
int a[NMAX];

vector <int> graph[NMAX];

int sz;
int first[NMAX];
int last[NMAX];
int ans[NMAX];

int anss[NMAX];
lint dist[NMAX];
int stkSz;
int stk[NMAX];

void dfs(int node) {
    first[node] = ++ sz;

    int st = 1;
    int dr = stkSz;
    int ans = stkSz + 1;

    while (st <= dr) {
        int mid = (st + dr) >> 1;
        if (dist[node] - dist[stk[mid]] <= a[node]) {
            ans = mid;
            dr = mid - 1;
        }
        else
            st = mid + 1;
    }

    if (ans <= stkSz) {
        anss[stk[stkSz]] ++;
        anss[p[stk[ans]]] --;
    }

    stk[++ stkSz] = node;

    for (auto it: graph[node]) {
        dist[it] = dist[node] + w[it];
        dfs(it);
    }
    -- stkSz;
    last[node] = ++ sz;

    for (auto it: graph[node])
        anss[node] += anss[it];
}

int main()
{
    ios_base :: sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 1; i <= N; ++ i)
        cin >> a[i];

    for (int i = 2; i <= N; ++ i) {
        cin >> p[i] >> w[i];
        graph[p[i]].push_back(i);
    }

    dfs(1);
    for (int i = 1; i <= N; ++ i)
        cout << anss[i] << " \n"[i == N];
    return 0;
}