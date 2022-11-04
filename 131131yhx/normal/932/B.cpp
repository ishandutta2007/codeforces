#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <map>
#include <set>
#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int F(int x) {
    int ans = 1;
    while(x) {
        if(x % 10) ans *= (x % 10);
        x /= 10;
    }
    return ans;
}

int G[1000010], S[1000010][10];

int main() {
    for(int i = 0; i < 10; i++) G[i] = i;
    for(int i = 10; i <= 1000000; i++)
        G[i] = G[F(i)];
    S[0][0] = 1;
    for(int i = 1; i <= 1000000; i++) {
        memcpy(S[i], S[i - 1], sizeof(S[i - 1]));
        S[i][G[i]]++;
    }
    int Q;
    scanf("%d", &Q);
    while(Q--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        printf("%d\n", S[b][c] - S[a - 1][c]);
    }
    return 0;
}