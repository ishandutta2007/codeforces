n,m,k = map(int,input().split())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
A = [0 for i in range(n+1)]
B = [0 for i in range(m+1)]
ct = 0
for i in range(n):
	if(a[i] == 0):
		ct = 0
	else:
		ct += 1
		A[ct] += 1
ct = 0
for i in range(m):
	if(b[i] == 0):
		ct = 0
	else:
		ct += 1
		B[ct] += 1
for i in range(n-1,0,-1):
	A[i] += A[i+1]
for i in range(m-1,0,-1):
	B[i] += B[i+1]
i = 1
ans = 0
while(i*i <= k):
	if(k%i == 0):
		if(i <= n and k//i <= m):
			ans += A[i]*B[k//i]
		if(i*i != k  and i <= m and k//i <= n):
			ans += B[i]*A[k//i]
	i += 1
print(ans)