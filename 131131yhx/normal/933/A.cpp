#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>
#include <ctime>
#include <vector>
#include <bitset>

using namespace std;

int n, L[2010], F[2010][5];

void cmax(int &x, int y) {
    if(x < y) x = y;
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &L[i]);
    memset(F, 200, sizeof F);
    for(int i = 0; i <= 4; i++) F[0][i] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= 4; j++) F[i][j] = F[i - 1][j];
        if(L[i] == 1) {
            cmax(F[i][0], F[i - 1][0] + 1);
            cmax(F[i][2], F[i - 1][2] + 1);
        } else {
            cmax(F[i][1], F[i - 1][1] + 1);
            cmax(F[i][3], F[i - 1][3] + 1);
        }
        for(int j = 1; j <= 4; j++) cmax(F[i][j], F[i][j - 1]);
    }
    printf("%d\n", F[n][4]);
    return 0;
}