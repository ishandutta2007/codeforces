from math import *
n,m = map(int,input().split())
a = list(map(int,input().split()))
maxx = 0
for i in range(n):
	if(maxx <= ceil(a[i]/m)):
		maxx = ceil(a[i]/m)
		ind = i+1
print(ind)