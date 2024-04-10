#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <bitset>

using namespace std;

typedef long long ll;

char ch[2][2010][2010];

ll X[2][2010][2010], _mul[2010 * 2010];

int n, m;

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i <= 2009 * 2009; i++) _mul[i] = !i ? 1 : _mul[i - 1] * 233;
    for(int i = 1; i <= n; i++) scanf("%s", ch[0][i] + 1);
    for(int i = 1; i <= m; i++) scanf("%s", ch[1][i] + 1);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            X[0][i][j] = (X[0][i - 1][j] + X[0][i][j - 1] - X[0][i - 1][j - 1] + _mul[i * 2005 + j] * ch[0][i][j]);
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
            X[1][i][j] = (X[1][i - 1][j] + X[1][i][j - 1] - X[1][i - 1][j - 1] + _mul[i * 2005 + j] * ch[1][i][j]);
    for(int i = m; i <= n; i++)
        for(int j = m; j <= n; j++) {
            ll A = (X[0][i][m] - X[0][i - m][m]) * _mul[j - m], B = (X[1][m][j] - X[1][m][j - m]) * _mul[(i - m) * 2005];
            if(A == B) {
                printf("%d %d\n", i - m + 1, j - m + 1);
                return 0;
            }
        }
}