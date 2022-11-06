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
const int P = 1e9-1e6;
const int V = 100100;
int a[V];
int _, n;
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        int id = 0;
        for (int i = 1; i < n; ++i) if (a[i] < a[id]) id = i;
        printf("%d\n", n - 1);
        int xs = 1;
        for (int i = 0; i < n; ++i)
            if (i < id) printf("%d %d %d %d\n", i + 1, id + 1, P + a[id] + i - id, a[id]);
            else if (i > id) printf("%d %d %d %d\n", i + 1, id + 1, P + a[id] + id - i, a[id]);
    }
    return 0;
}

/*
2
5
9 6 3 11 15
3
7 5 13
*/