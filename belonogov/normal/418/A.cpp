#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)
const int maxn = -1;
const int inf = 1e9;


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;
    if (k * 2 < n) {
        printf("%d\n", n * k);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < k; j++)
                printf("%d %d\n", i + 1, (i + (j + 1)) % n + 1);
    }
    else {
        printf("-1\n");
    }




    return 0;
}