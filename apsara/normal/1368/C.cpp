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

int x[] = {0, 0, 0, 1, 1, 2, 2, 2};
int y[] = {0, 1, 2, 0, 2, 0, 1, 2};
int n;


int main() {
    while (~scanf("%d", &n)) {
        printf("%d\n", 7 * (n + 1) + 1);
        for (int i = 0; i < n + 1; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (i != 0 && j == 0) continue;
                printf("%d %d\n", 2 * i + x[j], 2 * i + y[j]);
            }
        }
    }
    return 0;
}

/*

*/