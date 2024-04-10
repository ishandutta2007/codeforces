#include <iostream>
#include <ctime>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <cstring>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <fstream>
#include <cstdio>
#include <cassert>
#include <bitset>

using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#define forit(it, s) for (__typeof(s.begin()) it = s.begin(); it != s.end(); it++)
#define sz(a) (int)a.size()
#define ll long long
#define pii pair<int,int>
#define vi vector<int>

const int inf = (int)1e9;
const int mod = (int)1e9 + 7;

int n, e;
vector<pii> edges;
int team[100100];
vector<int> g[1001000];
int x[30];
int N = 0;
int f[1001000];
set<pii> q;
int col[1001000];

int main () {

    srand('A' + 'I' + 'D' + 'O' + 'S');

    scanf("%d%d", &n, &e);
    for (int i = 0; i < e; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        x--; y--;
        edges.pb(mp(x, y));
    }
    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", x + j);
            N = max(N, x[j] - 1);
        }
        team[i] = x[rand() % k] - 1;
        if (i) printf(" ");
        printf("%d", team[i] + 1);
    }
    printf("\n");

    for (int i = 0; i < e; i++) {
        int x = edges[i].f;
        int y = edges[i].s;
        g[team[x]].pb(team[y]);
        g[team[y]].pb(team[x]);
    }

    N++;
    G:;
    for (int i = 0; i < N; i++) col[i] = rand() % 2 + 1;

    for (int i = 0; i < N; i++) {
        int opos = 0;
        forit (it, g[i]) {
            int to = *it;
            if (col[i] != col[to]) opos++;
        }
        int neigh = sz(g[i]) - opos;
        f[i] = opos - neigh;
        q.insert(mp(f[i], i));
    }

    while (true) {
        pii p = *q.begin();
        if (p.f >= 0) break;

        q.erase(q.begin());
        int v = p.s;
        f[v] = -f[v];
        q.insert(mp(f[v], v));
        forit (it, g[v]) {
            int to = *it;
            if (col[v] == col[to]) {
                q.erase(mp(f[to], to));
                f[to]++;
                q.insert(mp(f[to], to));
            } else {
                q.erase(mp(f[to], to));
                f[to]--;
                q.insert(mp(f[to], to));
            }
        }
        col[v] = 3 - col[v];
    }
int tmpr = 0;
for (int i = 0; i <  e; i++) {
   if (col[team[edges[i].f]]  != col[team[edges[i].s]]) tmpr++; 
}
if (tmpr >= e / 2) {
	
} else {
	q.clear();
	srand(time(NULL));
	goto G;
	assert(0);
}
    for (int i = 0; i < N; i++) {
        if (i) printf(" ");
        printf("%d", col[i]);
    }
    printf("\n");

	return 0;
}