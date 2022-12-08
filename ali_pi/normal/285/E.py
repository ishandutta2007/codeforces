mod=10**9+7
n,k=map(int,raw_input().split())
A=[0]*(n+1)
B=[0]*(n+1)
C=[0]*(n+1)
F=[0]*(n+1)
G=[0]*(n+1)
F[0]=G[0]=1
for i in range(1,n+1):
	G[i]=F[i]=F[i-1]*i%mod
	G[i]=pow(F[i],(mod-2),mod)
for i in range(0,n):
	if i*2>n:
		break
	B[i]=(F[n-i]*G[i]*G[n-i*2])%mod
for i in range(0,n//2+1):
	for j in range(0,n//2+1):
		A[i+j]=(A[i+j]+B[i]*B[j])%mod
for i in range(0,n+1):
	A[i]=A[i]*F[n-i]%mod
for i in range(0,n+1):
	for j in range(0,i+1):
		C[j]=(C[j]+A[i]*F[i]*G[j]*G[i-j]*(1-(i-j)%2*2))%mod
print(C[k]%mod)