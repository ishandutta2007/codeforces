#include <stdio.h>
#include <algorithm>

int n, m;
int A[100500], B[100500], X[100500];
int U[100500], V[100500];
int L[100500], M[100500], S, F;

bool cmpX(const int &a, const int &b) { return A[a] != A[b] ? A[a] < A[b] : B[a] > B[b]; }
int main() {
 scanf("%d%d", &n,&m);
 for(int i = 1; i <= m; i++) scanf("%d%d", A+i,B+i), X[i] = i;
 std::sort(X+1, X+m+1, cmpX);

 int p = 1;
 for(int i = 1; i <= m; i++) {
  int e = X[i]; int a = A[e], b = B[e];
  int &u = U[e]; int &v = V[e];
  if(b == 1) {
   ++p; u = p-1; v = p;
   for(int z = 1; z < p-1 && S <= m; z++) { ++S; L[S] = z, M[S] = p; }
  }else {
   if(F >= S) return 0 & puts("-1");
   ++F; u = L[F]; v = M[F];
  }
 } 

 for(int i =1; i <= m; i++) printf("%d %d\n",U[i],V[i]);
 return 0;
}