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
int _, n, K, m, x;
int s[V];

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d%d", &n, &K, &m);
        int sz = K / 2;
        bool ok = false;
        for (int i = 1; i <= n; ++i) s[i] = 0;
        for (int i = 0; i < m; ++i) {scanf("%d", & x); s[x] = 1;}
        for (int i = 1; i <= n; ++i) s[i] += s[i - 1];
        int re = n - m;
        for (int i = 1; i <= n; ++i) {
            if (s[i] == s[i - 1]) continue;
            int L = i - s[i];
            int R = re - L;
            if (L >= sz && R >= sz) ok = true;
        }
        if (re % (K - 1) != 0) ok = false;
        if (ok) puts("YES");
        else puts("NO");
    }
    return 0;
}

/*
4
3 3 1
1
7 3 3
1 5 7
10 5 3
4 5 6
13 7 7
1 3 5 7 9 11 12
*/