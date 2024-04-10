#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <deque>
#include <utility>
#include <bitset>
#include <limits.h>

using namespace std;
typedef long long ll;
typedef double lf;
typedef long double llf;
typedef unsigned long long llu;
const int INF = 987654321;
const ll LINF = (ll)1e15;

const int SZ = 1505;

int N, M;
char D[SZ][SZ];

int QueX[SZ*SZ], QueY[SZ*SZ], Qf, Qr;
bool Chk[SZ][SZ];
int Len[SZ][SZ];
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

void push (int x, int y, int l) {
    if(x > 0 && y > 0 && x <= N && y <= M && D[x][y] != 'T' && !Chk[x][y]) {
        ++Qr;
        Chk[x][y] = true;
        Len[x][y] = l;
        QueX[Qr] = x; QueY[Qr] = y;
    }
}

int main() {
    int i, j, k;
    
    scanf("%d%d", &N, &M);
    for(i = 1; i <= N; i++) scanf("%s", D[i]+1);
    
    for(i = 1; i <= N; i++) {
        for(j = 1; j <= M; j++) {
            if(D[i][j] == 'E') break;
        }
        if(j <= M) {
            push(i, j, 1);
            break;
        }
    }
    
    
    
    while(Qf < Qr) {
        ++Qf; int x = QueX[Qf], y = QueY[Qf];
        for(i = 0; i < 4; i++) {
            push(x + dx[i], y + dy[i], Len[x][y] + 1);
        }
    }
    
    for(i = 1; i <= N; i++) {
        for(j = 1; j <= M; j++) {
            if(D[i][j] == 'S') break;
        }
        if(j <= M) {
            k = Len[i][j];
            break;
        }
    }

    int res = 0;
    
    for(i = 1; i <= N; i++) {
        for(j = 1; j <= M; j++) {
            if(D[i][j] >= '1' && D[i][j] <= '9' && Chk[i][j] && Len[i][j] <= k) {
                res += D[i][j] - '0';
            }
        }
    }
    
    printf("%d\n", res);
    
    return 0;
}