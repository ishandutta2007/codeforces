/*
HACK ME IF YOU CAN!















*/
#include <iostream>
#include <stdio.h>
#include <vector>
#include <climits>
#include <cstring>
#include <algorithm>
#include <set>
#include <bits/stdc++.h>
#include <queue>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/detail/standard_policies.hpp>
#define mp make_pair
#define pb push_back
#define fc first
#define sc second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ll long long
#define ld long double

#define max(a, b) (a > b ? a : b)

using namespace std;

const int MAXN = 3000 + 7;
int d[MAXN][MAXN];
vector <int> g[MAXN];
vector <int> prv[MAXN];
vector <int> pro[MAXN];
vector <pair <int, int> > gi[MAXN];
vector <pair <int, int> > go[MAXN];

bool used[MAXN];
int lenv[MAXN], leno[MAXN];
bool can[MAXN][MAXN];

void bfs(int v) {
    queue <int> q;
    q.push(v);
    int s = v;
    used[v] = 1;
    while (!q.empty()) {
        v = q.front();
        q.pop();
        for (int i = 0; i < (int) g[v].size(); i++) {
            int to = g[v][i];
            if (!used[to]) {
                used[to] = 1;
                q.push(to);
                d[s][to] = d[s][v] + 1;
            }
        }
    }
}

main() {
    #ifdef __linux__
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    #ifndef __linux__
        //
        //
    #endif 
    int n, m, u, v;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        can[u][v] = 1;
    }   
    for (int i = 1; i <= n; i++) {
        bfs(i);
        memset(used, 0, sizeof used);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (d[i][j] != 0) {
                gi[j].pb(mp(d[i][j], i));
                go[i].pb(mp(d[i][j], j));
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        sort(rall(gi[i]));
        sort(rall(go[i]));
    }
    int len_ans = -1;
    int a = 0, b = 0, c = 0, e = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (d[i][j] != 0) {
                for (int k = 0; k < min((int) gi[i].size(), 3); k++) {
                    for (int z = 0; z < min((int) go[j].size(), 3); z++) {
                        int p1 = gi[i][k].second;
                        int l1 = gi[i][k].first;
                        int p4 = go[j][z].second;
                        int l4 = go[j][z].first;
                        if (l1 + d[i][j] + l4 > len_ans && p1 != j && p4 != i && p1 != p4) {
                            len_ans = l1 + d[i][j] + l4;
                            a = p1, b = i, c = j, e = p4;
                        }
                    }
                }
            }
        }
    }
    cout << a << " " << b << " " << c << " " << e << endl;
}