#include<bits/stdc++.h>
int m(int N, int* A, int M, int* B, int K) {
 if(N==0||M==0) return 1<<K;
 if(K==0) return 0;
 int X=std::lower_bound(A, A+N, ((A[0]>>K-1)|1)<<K-1)-A;
 int Y=std::lower_bound(B, B+M, ((B[0]>>K-1)|1)<<K-1)-B;
 if(X==0&&Y==M||X==N&&Y==0) return m(N, A, M, B, K-1)+(1<<K-1);
 return std::min(m(X, A, Y, B, K-1), m(N-X, A+X, M-Y, B+Y, K-1));
}
long long solve(int N, int* A, int K) {
 if(N==1) return 0;
 int X=std::lower_bound(A, A+N, ((A[0]>>K-1)|1)<<K-1)-A;
 if(X==0||X==N) return solve(N, A, K-1);
 return (1<<K-1)+m(X, A, N-X, A+X, K-1)+solve(X, A, K-1)+solve(N-X, A+X, K-1);
}
int N, A[200000];
int main() {
 scanf("%d", &N);
 for(int i=0; i<N; ++i) scanf("%d", A+i);
 std::sort(A, A+N); N=std::unique(A, A+N) - A;
 printf("%lld\n", solve(N, A, 30));
}