from math import *
test = 1
#test = int(input())
for __ in range(test):
	n,x,k = map(int,input().split())
	a = list(map(int,input().split()))
	d = dict()
	if(x == 1 and k == 0):
		print(0)
		continue
	for i in range(n):
		y = (a[i]-1)//x
		if(y not in d):
			d[y] = 0
		d[y] += 1
	ans = 0
	#print(d)
	for i in range(n):
		y = a[i]//x
		if(y-k not in d):
			continue
		ans += d[y-k]
	if(k == 0):
		sz = len(set(a))
		ans -= sz*(sz-1)//2
	print(ans)