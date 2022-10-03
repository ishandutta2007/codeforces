#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")

using namespace std;
const int mod=1000000007, N=17;

int n, x, ans;
int A[1<<N], B[N+1][1<<N], C[N+1][1<<N], D[1<<N], E[1<<N];
long long fib[1<<N];

inline void fix(int &x){
	if (x>=mod) x-=mod;
	if (x<0) x+=mod;
}

void SOS1(int* A, int inv){
	for (int j=0; j<N; j++) for (int mask=0; mask<(1<<N); mask++) if (mask&(1<<j))
		fix(A[mask]+=inv*A[mask^(1<<j)]);
}

void SOS2(int* A, int inv){
	for (int j=0; j<N; j++) for (int mask=0; mask<(1<<N); mask++) if (mask&(1<<j))
		fix(A[mask^(1<<j)]+=inv*A[mask]);
}

void XOR(int* A, bool inv){
	for (int j=0; j<N; j++) for (int mask=0; mask<(1<<N); mask++) if (mask&(1<<j)){
		int a=A[mask^(1<<j)], b=A[mask];
		fix(A[mask^(1<<j)]=a+b);
		fix(A[mask]=a-b);
	}
	if (inv){
		long long tmp=1, inv2=(mod+1)/2;
		for (int i=0; i<N; i++) tmp=tmp*inv2%mod;
		for (int mask=0; mask<(1<<N); mask++) A[mask]=A[mask]*tmp%mod;
	}
}

int main(){
	fib[1]=1;
	for (int i=2; i<(1<<N); i++) fib[i]=(fib[i-1] + fib[i-2])%mod;
	
	scanf("%d", &n);
	while (n--) scanf("%d", &x), A[x]++;
	
	for (int i=0; i<=N; i++){
		for (int mask=0; mask<(1<<N); mask++)
			if (__builtin_popcount(mask)==i) B[i][mask]=A[mask];
		SOS1(B[i], +1);
	}
	for (int i=0; i<=N; i++) for (int j=0; i+j<=N; j++){
		for (int mask=0; mask<(1<<N); mask++)
			C[i+j][mask]=(C[i+j][mask] + 1ll*B[i][mask]*B[j][mask])%mod;
	}
	for (int i=0; i<=N; i++) SOS1(C[i], -1);
	for (int mask=0; mask<(1<<N); mask++)
		D[mask]=C[__builtin_popcount(mask)][mask]*fib[mask]%mod;
	
	for (int mask=0; mask<(1<<N); mask++){
		E[mask]=A[mask];
		A[mask]=A[mask]*fib[mask]%mod;
	}
	
	XOR(E, 0);
	for (int mask=0; mask<(1<<N); mask++) E[mask]=1ll*E[mask]*E[mask]%mod;
	XOR(E, 1);
	for (int mask=0; mask<(1<<N); mask++) E[mask]=E[mask]*fib[mask]%mod;
	
	SOS2(A, +1);
	SOS2(D, +1);
	SOS2(E, +1);
	for (int mask=0; mask<(1<<N); mask++) A[mask]=1ll*A[mask]*D[mask]%mod*E[mask]%mod;
	SOS2(A, -1);
	
	for (int i=0; i<N; i++) fix(ans+=A[1<<i]);
	if (ans<0) ans+=mod;
	printf("%d\n", ans);
	
	return 0;
}