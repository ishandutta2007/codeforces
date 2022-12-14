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
#include <numeric>
#include <deque>
#include <utility>
#include <bitset>
#include <limits.h>
#include <iostream>

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;

const int N_ = 505, M_ = 1050;

int N, M;
int W[N_], D[M_];
bool used[N_];
int pile[N_], pile_n;
int ans;

int main() {
    scanf("%d%d", &N, &M);
    for(int i = 1; i <= N; i++) {
        scanf("%d", &W[i]);
    }
    for(int i = 1; i <= M; i++) {
        scanf("%d", &D[i]);
        if(!used[D[i]]) pile[++pile_n] = D[i], used[D[i]] = true;
    }
    for(int i = 1; i <= N; i++) if(!used[i]) pile[++pile_n] = i;
    
    for(int i = 1; i <= M; i++) {
        for(int j = 1; j <= N; j++) {
            if(pile[j] == D[i]) {
                for(int k = j; k > 1; k--) pile[k] = pile[k - 1];
                pile[1] = D[i];
                break;
            }
            ans += W[pile[j]];
        }
    }
    
    printf("%d\n", ans);
    
    
    return 0;
}