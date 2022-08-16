mod = 998244353
def modinv(x):
	res = 1
	y = mod - 2
	while(y):
		if(y&1): res = (res*x)%mod
		x = (x*x)%mod
		y //= 2
	return res

n,m = map(int,input().split())
a = [1]
t = [1]
for i in range(1,m+1):
	a.append((a[-1]*i)%mod)
	t.append((t[-1]*2)%mod)
num = (a[m]*t[n-2])%mod
den = (a[n-1]*a[m-n+1]*2)%mod
num = (num*(n-2))%mod
print((num*modinv(den))%mod)