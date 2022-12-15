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

using namespace std;
typedef long long ll;
const int INF = 987654321;
const ll LINF = 1e15;

const int N_ = 5005;

int N;

ll D[N_], E[N_];
int P2[N_];

int Table[N_];
int res = -1;

int main() {
    int i, j, k;
    
    scanf("%d", &N);
    for(i = 1; i <= N; i++) {
        scanf("%I64d", &D[i]);
        ll &tmp = E[i]; tmp = D[i];
        while((tmp & 1) == 0) tmp >>= 1, ++P2[i];
    }

    for(i = N; i > 0; i--) {
        Table[i] = 1;
        for(j = i + 1; j <= N; j++) {
            bool c1 = (Table[i] <= Table[j]);
            bool c2 = (E[i] % E[j] == 0);
            bool c3 = (P2[j] == P2[i] + (j - i) || P2[j] < (j - i));
            if(c1 && c2 && c3) Table[i] = Table[j] + 1;
        }
    }

    for(i = 1; i <= N; i++){
        res = max(res, Table[i]);
    }

    printf("%d\n", N - res);
    return 0;
}