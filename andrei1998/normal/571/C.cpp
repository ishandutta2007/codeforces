#include <bits/stdc++.h>

#define NMAX 200005
using namespace std;

int n, m;

vector <pair <int, int> > graph[NMAX];
int st[NMAX];
int dr[NMAX];

int graph2[NMAX][2];

bitset <NMAX> vis;

bool ans[NMAX];

bool bad_st[NMAX];
bool bad_dr[NMAX];

bool cupl (int node) {
    if (vis[node])
        return false;
    vis[node] = true;

    for (auto it: graph[node])
        if (!bad_dr[it.first] && !dr[it.first]) {
            st[node] = it.first;
            dr[it.first] = node;
            ans[node] = it.second;

            return true;
        }

    for (auto it: graph[node])
        if (!bad_dr[it.first] && cupl(dr[it.first])) {
            st[node] = it.first;
            dr[it.first] = node;
            ans[node] = it.second;

            return true;
        }

    return false;
}

bool cuplaj () {
    bool ok = true;
    while (ok) {
        vis &= 0;
        ok = false;

        for (int i = 1; i <= m; ++ i)
            if (!bad_st[i] && !st[i] && cupl(i))
                ok = true;
    }

    int cate = 0;
    for (int i = 1; i <= n; ++ i)
        if (bad_dr[i] || dr[i])
            cate ++;

    if (cate == n)
        return true;
    return false;
}

int main()
{
    ios_base :: sync_with_stdio(false);

    cin >> n >> m;

    int k, x;
    for (int i = 1; i <= n; ++ i) {
        cin >> k;

        while (k --) {
            cin >> x;
            if (x > 0) {
                if (graph2[x][1]) {
                    bad_st[x] = 1;
                    bad_dr[graph2[x][1]] = 1;
                    bad_dr[i] = 1;

                    ans[x] = 1;
                }

                graph2[x][1] = i;
                graph[x].push_back(make_pair(i, 1));
            }
            else {
                x = -x;

                if (graph2[x][0]) {
                    bad_st[x] = 1;
                    bad_dr[graph2[x][0]] = 1;
                    bad_dr[i] = 1;

                    ans[x] = 0;
                }

                graph2[x][0] = i;
                graph[x].push_back(make_pair(i, 0));
            }
        }
    }

    if (!cuplaj()) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";

    for (int i = 1; i <= m; ++ i)
        cout << ans[i];
    cout << '\n';

    return 0;
}