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

const int N_ = 2000005;

int N;
int Res[N_], A[N_];

int main() {
    int i, j, k;

    scanf("%d", &N);
    for(i = 1; i <= N; i++) Res[i] = A[i] = i;
    
    for(i = 0; i < N - 1; i++) {
        int t = -1;
        for(k = i; k < i + N; k += (i + 2)) {
            j = Res[k]; A[j] += i + 2;
            if(A[j] > i + N) A[j] = i + N;
            t = k;
        }
        while(t >= i) {
            int a = A[Res[t]];
            Res[a] = Res[t];
            t -= (i + 2);
        }
    }
    
    for(i = N - 1, j = 0; ++j <= N; i++) {
        printf("%d ", Res[i] + 1);
    }
    return 0;
}