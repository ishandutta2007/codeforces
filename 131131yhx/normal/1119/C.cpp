#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <bitset>

#define PII pair <int, int>
#define x first
#define y second

using namespace std;

typedef long long ll;

int n, m, A[555][555], B[555][555], X[555], Y[555];

signed main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            scanf("%d", &A[i][j]);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            scanf("%d", &B[i][j]);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(A[i][j] != B[i][j]) X[i] ^= 1, Y[j] ^= 1;
    for(int i = 1; i <= n; i++)
        if(X[i]) {
            puts("No");
            return 0;
        }
    for(int i = 1; i <= m; i++)
        if(Y[i]) {
            puts("No");
            return 0;
        }
    puts("Yes");
    return 0;
}