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
const int V = 100100;
struct Node{
    int a, c;
}e[V];

bool cmp(Node x, Node y) {
    if (x.a != y.a) return x.a < y.a;
    else return x.c < y.c;
}

int n;

int main() {
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; ++i) scanf("%d%d", &e[i].a, &e[i].c);
        sort(e, e + n, cmp);
        LL ans = 0;
        int cur = e[0].a + e[0].c;
        for (int i = 0; i < n; ++i) {
            ans += e[i].c;
            ans += max(0, e[i].a - cur);
            cur = max(cur, e[i].a + e[i].c);
        }
        printf("%I64d\n", ans);
    }
    return 0;
}

/*
3
1 9
2 1
4 1

6
4 2
8 4
3 0
2 3
7 1
0 1
*/