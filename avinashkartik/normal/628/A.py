from math import *
n,b,p = map(int,input().split())
m = n
ct = 0
while(n > 1):
	x = 1<<(int(log2(n))-1)
	ct += x
	n -= x
print((2*b+1)*ct,p*m)