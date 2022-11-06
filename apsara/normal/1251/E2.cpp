#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define fi first
#define se second
#define MP make_pair
const int P = 1000000007;

const int V = 200100;

int _, n, m[V], p[V];

int s[V];

vector<int> g[V];

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d%d", &m[i], &p[i]);
        for (int i = 0; i < n; ++i) g[i].clear();
        for (int i = 0; i < n; ++i) g[m[i]].PB(p[i]);
        for (int i = 0; i < n; ++i) sort(g[i].begin(), g[i].end());
        LL cost = 0;
        s[0] = g[0].size();
        for (int i = 1; i < n; ++i) s[i] = s[i - 1] + g[i].size();
        priority_queue<int, vector<int>, greater<int> > Q;
        int cur = 0;
        for (int i = n - 1; i > 0; --i) {
            for (auto x : g[i]) Q.push(x);
            while (cur + s[i - 1] < i) {
                cost += Q.top();
                Q.pop();
                cur++;
            }
        }
        printf("%I64d\n", cost);
    }
    return 0;
}

/*
3
3
1 5
2 10
2 8
7
0 1
3 1
1 1
6 1
1 1
4 1
4 1
6
2 6
2 3
2 8
2 7
4 4
5 5

*/