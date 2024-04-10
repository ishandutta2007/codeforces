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

const int N_ = 205;

int N;
char D[N_][N_];

int main() {
    int i, j, k;
    
    scanf("%d", &N);
    for(i = 1; i <= N; i++) scanf("%s", D[i]+1);
    
    bool vchk = true;
    for(i = 1; i <= N && vchk; i++) {
        for(j = 1; j <= N; j++) {
            if(D[i][j] == '.') break;
        }
        if(j > N) vchk = false;
    }
    
    if(vchk) {
        for(i = 1; i <= N; i++) {
            for(j = 1; j <= N; j++) {
                if(D[i][j] == '.') {
                    printf("%d %d\n", i, j);
                    break;
                }
            }
            if(j > N) break;
        }
        return 0;
    }
    
    bool hchk = true;
    for(i = 1; i <= N && hchk; i++) {
        for(j = 1; j <= N; j++) {
            if(D[j][i] == '.') break;
        }
        if(j > N) hchk = false;
    }
    
    if(hchk) {
        for(i = 1; i <= N; i++) {
            for(j = 1; j <= N; j++) {
                if(D[j][i] == '.') {
                    printf("%d %d\n", j, i);
                    break;
                }
            }
            if(j > N) break;
        }
        return 0;
    }
    
    puts("-1");
    return 0;
}