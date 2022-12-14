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
#include <time.h>
#include <functional>
#include <numeric>
 
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

#define debug(format, ...) printf(format, __VA_ARGS__);

const int N_  = 200500;
int N, A, B, K;
char S[N_];
vector<int> ans;

int main() {
    scanf("%d%d%d%d%s", &N, &A, &B, &K, S+1);

    int con = 0;
    for(int i = 1; i <= N; i++) {
    	if(S[i] == '0') {
    		con += 1;
    		if(con % B == 0) ans.push_back(i);
    	}else if(S[i] == '1') {
    		con = 0;
    	}
    }

    for(int i = 1; i <= A-1 && !ans.empty(); i++)
    	ans.pop_back();

    printf("%lu\n", ans.size());
    for(auto x : ans) printf("%d ", x);
    return 0;
}