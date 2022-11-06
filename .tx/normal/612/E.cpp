#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <string>
#include <memory.h>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rvei(a, n) for (int i = 0; i < n; i++) sci(a[i])
#define rveid(a, n) vector<int> a(n); rvei(a, n)

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;

using namespace std;

int p[1111111];
int q[1111111];
int qa[1111111];

vector< vector<int> > cycles[1111111];

bool used[1111111];

void dfs(int v, vector<int>& cycle) {
    used[v] = true;
    cycle.push_back(v);
    if (!used[p[v]]) {
        dfs(p[v], cycle);
    }
}

void fill(int v, int to) {
    if (q[v] != -1) {
        return;
    }
    q[v] = to;
    fill(p[to], v);
}

int main() {
    scid(n);
    for (int i = 0; i < n; i++) {
        sci(p[i]);
        --p[i];
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            vector<int> c;
            dfs(i, c);
            cycles[c.size()].push_back(c);
        }
    }

    memset(q, -1, sizeof(int) * 1111111);

    for (int i = 2; i <= n; i+= 2) {
        if (cycles[i].size() % 2 != 0) {
            puts("-1");
            return 0;
        }
        for (int j = 0; j < cycles[i].size(); j += 2) {
            fill(cycles[i][j][0], cycles[i][j + 1][0]);
        }
    }

    for (int i = 1; i <= n; i += 2) {
        for (int j = 0; j < cycles[i].size(); j++) {
            fill(cycles[i][j][0], cycles[i][j][cycles[i][j].size() / 2]);
        }
    }

    for (int i = 0; i < n; i++) {
        qa[q[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        cout << qa[i] + 1 << " ";
    }

    return 0;
}