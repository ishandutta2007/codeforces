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
char s[V];
int _, n, res[V];
void small() {
    int sn = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == '<') sn++;
    }
    int M = n;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == '>') res[i] = M--;
        else res[i] = sn--;
    }
    res[n - 1] = M;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == '<') {
            int r = i;
            while (r != n && s[r] == '<') ++r;
            for (int x = i, y = r - 1; x < y; ++x, --y) swap(res[x], res[y]);
            i = r;
        }
    }
    for (int i = 0; i < n; ++i) printf("%d ", res[i]); puts("");
}

void big() {
    int sn = 1;
    int M = n;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == '>') res[i] = M--;
        else res[i] = sn++;
    }
    res[n - 1] = M;
    for (int i = 0; i < n; ++i) printf("%d ", res[i]); puts("");
}

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        scanf("%s", s);
        small();
        big();
    }
    return 0;
}

/*
3
3 <<
7 >><>><
5 >>><
*/