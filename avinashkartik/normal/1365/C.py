from math import *
n = int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
d = dict()
for i in range(n):
	d[a[i]] = i
dif = dict()
for i in range(n):
	x = (i - d[b[i]])%n
	if(x in dif):
		dif[x] += 1
	else:
		dif[x] = 1
print(max(dif.values()))