#include <stdio.h>
#include <algorithm>

const int N_ = 300005;

struct S {
 int v, x;
 S(int v = 0, int x = 0): v(v), x(x) { }
 bool operator< (const S &s) const { return v < s.v; }
};

int N, Res[N_];
S D[N_];

int main(){
 int i, j;
 scanf("%d", &N);
 for(i = 1; i <= N; i++) scanf("%d", &D[i].v), D[i].x = i;
 
 std::sort(D+1, D+N+1);

 for(i = 1, j = 0; i <= N; i++) {
   if(j < D[i].v) j = D[i].v;
   Res[D[i].x] = j;
   ++j;
 }

 for(i = 1; i <= N; i++) printf("%d ", Res[i]);
 return 0;
}