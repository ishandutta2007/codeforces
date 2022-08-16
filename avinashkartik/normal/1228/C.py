from math import *
a = []
mod = 10**9+7

def primeFactors(n): 
	i = 2
	while(i*i <= n):
		if(n%i == 0):
			a.append(i)
		while n % i== 0:
			n //= i 
		i += 1
	if n > 1: 
		a.append(n)

def fastmod(x,y):
	res = 1
	while(y > 0):
		if(y&1): res = (res*x)%mod
		x = (x*x)%mod
		y //= 2
	return res

x,n = map(int,input().split())
primeFactors(x)
ans = 1
for i in a:
	s = i
	ct = 0
	while(s <= n):
		ct += n//s
		s *= i
	ans = (ans*fastmod(i,ct))%mod
print(ans)