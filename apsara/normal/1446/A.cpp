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
struct Node{int v, id;}e[V];
bool cmp(Node x, Node y) {return x.v > y.v;}
int _, ans[V], n, m;
LL W;


int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%lld", &n, &W);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &e[i].v);
            e[i].id = i + 1;
        }
        sort(e, e + n, cmp);
        LL s = 0;
        m = 0;
        for (int i = 0; i < n; ++i) {
            if (s + e[i].v > W) continue;
            ans[m++] = e[i].id;
            s += e[i].v;
        }
        if (s * 2 < W) puts("-1");
        else {
            printf("%d\n", m);
            sort(ans, ans + m);
            for (int i = 0; i < m; ++i) printf("%d ", ans[i]); puts("");
        }
    }
    return 0;
}

/*
3
1 3
3
6 2
19 8 19 69 9 4
7 12
1 1 1 17 1 1 1
*/