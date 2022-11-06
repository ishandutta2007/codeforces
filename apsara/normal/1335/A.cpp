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

int _, n;
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        printf("%d\n", (n - 1) / 2);
    }
    return 0;
}

/*
6
7
1
2
3
2000000000
763243547
*/