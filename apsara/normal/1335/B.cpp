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

int _, n, a, b, ans[2100];
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d%d", &n, &a, &b);
        for (int i = 0; i < b - 1; ++i) ans[i] = i;
        for (int j = b - 1; j < a; ++j) ans[j] = b - 1;
        for (int i = 0; i < n; ++i) printf("%c", 'a' + ans[i % a]);
        puts("");
    }
    return 0;
}

/*
4
7 5 3
6 1 1
6 6 1
5 2 2
*/