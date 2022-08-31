from collections import *
n = int(input())
a = list(map(int,input().split()))
o,e = 0,0
for i in a:
	if(i%2 == 0):
		e += 1
	else:
		o += 1
a.sort(reverse = True)
i = 0
ex,ox = min(o,e),min(o,e)
if(o > ox):
	ox += 1
if(e > ex):
	ex += 1
while(i < n and (ox or ex)):
	if(ex and a[i]%2 == 0):
		a[i] = 0
		ex -= 1
	if(ox and a[i]%2 == 1):
		a[i] = 0
		ox -= 1
	i += 1
print(sum(a))