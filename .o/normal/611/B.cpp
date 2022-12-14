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

vector<ll> S;

void solve(int x, int c, ll v) {
 if(c == 1) S.push_back(v);
 if(x == 62) return;
 solve(x + 1, c, v * 2 + 1);
 if(c == 0) solve(x + 1, 1, v * 2);
}

int main() {
solve(0, 0, 1);
sort(S.begin(), S.end());
ll a,b; scanf("%lld%lld",&a,&b);
int c = 0;
for(auto x : S) {
 if(a <= x && x <= b) ++c;
}
printf("%d\n", c);
    return 0;
}