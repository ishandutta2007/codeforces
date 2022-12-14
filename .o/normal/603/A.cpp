#define _CRT_SECURE_NO_WARNINGS

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
#include <unordered_map>
#include <unordered_set>
#include <time.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

char S[100500];
int N;

int main() {
    scanf("%d%s", &N, S);
    
    int cnt[2] = {0, 0};
    for(int i = 0; i < N-1; i++) {
        cnt[S[i] == S[i+1]]++;
    }
    printf("%d\n", cnt[0] + min(cnt[1], 2) + 1);
    return 0;
}