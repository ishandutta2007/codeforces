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

int _, n, K;
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d", &n, &K);
        if (n < K) printf("%d\n", K - n);
        else {
            if (n % 2 == K % 2) puts("0");
            else puts("1");
        }
    }
    return 0;
}

/*
6
4 0
5 8
0 1000000
0 0
1 0
1000000 1000000
*/