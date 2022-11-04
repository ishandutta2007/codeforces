#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <bitset>
#define M 200010

using namespace std;

typedef long long ll;

int n, A[M], mu[M];

bitset <7010> bt[100010];

bitset <7010> O[7010], K[7010];

int main() {
    for(int i = 1; i <= 7000; i++)
        for(int j = i; j <= 7000; j += i) O[j][i] = 1;
    mu[1] = 1;
    for(int i = 1; i <= 7000; i++)
        for(int j = i + i; j <= 7000; j += i) {
            mu[j] -= mu[i];
        }
    for(int i = 1; i <= 7000; i++)
        for(int j = 1; i * j <= 7000; j++)
            K[i][i * j] = !!mu[j];
    int n, q;
    scanf("%d%d", &n, &q);
    for(int T = 1; T <= q; T++) {
        int op, x, y, z, v;
        scanf("%d", &op);
        if(op == 1) {
            scanf("%d%d", &x, &v);
            bt[x] = O[v];
        } else if(op == 2) {
            scanf("%d%d%d", &x, &y, &z);
            bt[x] = bt[y] ^ bt[z];
        } else if(op == 3) {
            scanf("%d%d%d", &x, &y, &z);
            bt[x] = bt[y] & bt[z];
        } else {
            scanf("%d%d", &x, &v);
            int ans = (bt[x] & K[v]).count();
            printf("%d", ans & 1);
        }
    }
    putchar('\n');
    return 0;
}