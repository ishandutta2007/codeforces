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

int N, A, B, C, T[200500];
stack<int> vec[200500];
bool used[200500];
int S[8],X[8];

int main() {
scanf("%d%d%d%d",&N,&A,&B,&C); 

int V[] = {A,B,C}; sort(V, V+3);
for(int state =0 ; state < 8; state++) {
 S[state] = 0; X[state] = state;
 for(int x = 0; x < 3; x++) if((state >> x) & 1) S[state] += V[x];
}
//sort(X, X+8, [](const int &a, const int &b){return S[a] < S[b];});
X[0] = 1; X[1] = 2; X[2] = 4;
X[3] = 3; X[4] = 5; X[5] = 6;
X[6] = 7;

for(int i = 1; i <= N; i++) {
 scanf("%d", T+i);
}

sort(T+1, T+N+1);
for(int i = 1; i <= N; i++) {
 for(auto state : X){
  if(T[i] <= S[state]) vec[state].push(i);
 }
}

int ans = 0;

for(int i = N; i > 0; i--) if(!used[i]){
 int s = -1;
 for(auto state : X){
  if(T[i] <= S[state]) { s = state; break; }
 }
 if(s < 0) return 0 & puts("-1");
 used[i] = true; ans++;
 if(s == 7) continue;
 for(auto state : X) {
  if(s & state) continue;
  while(!vec[state].empty()) {
   int t = vec[state].top(); vec[state].pop();
   if(used[t]) continue;
   used[t] = true; s |= state;
   break;
  }
 }
}

printf("%d\n", ans);

    return 0;
}