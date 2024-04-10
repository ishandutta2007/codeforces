#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <ctime>


#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using namespace std;

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    int a = 1, b = 2;
    for (int i = 0; i < q; ++i) {
        int type;
        scanf("%d", &type);
        if (type == 2) {
            if (a & 1)
                ++a;
            else
                --a;
            if (b & 1)
                ++b;
            else
                --b;

        }
        else {
            int x;
            scanf("%d", &x);
            a += x;
            a = (a - 1 + n) % n + 1;
            b += x;
            b = (b - 1 + n) % n + 1;
        }
    }
    vector<int> ans(n);
    for (int i = 1; i <= n; ++i) {
        if (i & 1)
            ans[(i + a - 2 + n) % n] = i;
        else
            ans[(i + b - 3 + n) % n] = i;
    }
    for (int i = 0; i < n; ++i)
        printf("%d ", ans[i]);
    return 0;
}