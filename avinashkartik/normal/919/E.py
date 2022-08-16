from collections import *
from math import *

def inv(x,mod):
	y = mod-2
	res = 1
	while(y > 0):
		if(y&1): res = (res*x)%mod
		x = (x*x)%mod
		y //= 2
	return res

def findMinX(num, rem) :
    prod = 1
    for i in range(2) : 
        prod = prod * num[i] 
    result = 0
    for i in range(2): 
        pp = prod // num[i] 
        result = result + rem[i] * inv(pp, num[i]) * pp 
    return result % prod 

a,b,mod,x = list(map(int,input().split()))
ans = 0
p = mod*(mod-1)
r = x%p
q = x//p
res = 1
for i in range(1,mod):
	res = (res*a)%mod
	n = b*inv(res,mod)
	X = findMinX([mod,mod-1],[n,i%(mod-1)])
	ans += q
	if(X <= r):
		ans += 1
print(ans)