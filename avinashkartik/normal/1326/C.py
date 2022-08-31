n,k = map(int,input().split())
b = list(map(int,input().split()))
ct = 0
a = sorted(b)
ans = sum(a[n-k:])
ans2 = 1
f = 0
mod = 998244353
for i in range(n):
	ct += 1
	if(b[i] >= n-k+1):
		if(f): ans2 = (ans2*ct)%mod
		ct = 0
		f = 1
print(ans,ans2)