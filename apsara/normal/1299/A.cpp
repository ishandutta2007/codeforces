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
const int M = 31;
int a[V], n;

int main() {
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        int id = 0;
        for (int i = M; i >= 0; --i) {
            int cnt = 0;
            int tmp = -1;
            for (int j = 0; j < n; ++j) {
                if (a[j] & (1<<i)) cnt++, tmp = j;
            }
            if (cnt == 1) {
                id = tmp;
                break;
            }
        }
        printf("%d", a[id]);
        for (int i = 0; i < n; ++i) if(i != id) printf(" %d", a[i]);puts("");
    }
    return 0;
}

/*

*/