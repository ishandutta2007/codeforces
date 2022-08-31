from math import *
n,a,b,k = map(int,input().split())
l = list(map(int,input().split()))
for i in range(n):
	l[i] %= (a+b)
	if(l[i] == 0): l[i] = a+b
l.sort()
ct = 0
#print(l)
for i in range(n):
	l[i] -= a
	if(l[i] <= 0): ct += 1
	else:
		k -= ceil(l[i]/a)
		if(k < 0):
			break
		ct += 1
print(ct)