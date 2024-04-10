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

const int N_ = 200005;

int N, Q;
ll S[N_], D[N_];
ll sum;


int main() {
    int i, j, k;
    
    scanf("%d", &Q);

    N = 1;
    while(Q--) {
        scanf("%d", &k);
        if(k == 1){
            scanf("%d%d", &i, &j);
            sum += (ll)i * j;
            S[i] += j;
        }else if(k == 2){
            scanf("%d", &j);
            sum += j;
            D[++N] = j;
        }else {
            sum -= (D[N] + S[N]);
            S[N - 1] += S[N]; D[N] = S[N] = 0;
            --N;
        }

        printf("%.10Lf\n", (double)sum / N);
    }
    return 0;
}