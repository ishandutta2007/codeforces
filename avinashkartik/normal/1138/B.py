from collections import *
from math import *
n = int(input())
s = input()
t = input()
d = dict()
d["00"],d["01"],d["10"],d["11"] = 0,0,0,0
for i in range(n):
	x = s[i]+t[i]
	d[x] += 1
na = d["00"]
nb = d["01"]
nc = d["10"]
nd = d["11"]
for i in range(nb+1):
	for j in range(nc+1):
		b,c = i,j
		if (nb+nd-b-c)%2 == 1: continue
		d = (nb+nd-b-c)//2
		if(d < 0 or d > nd): continue
		a = (n//2)-b-c-d
		if(a < 0 or a > na): continue
		else:
			ans = []
			for i in range(n):
				x = s[i]+t[i]
				if(x == "00" and a != 0):
					ans.append(i+1)
					a -= 1
				if(x == "01" and b != 0):
					ans.append(i+1)
					b -= 1
				if(x == "10" and c != 0):
					ans.append(i+1)
					c -= 1
				if(x == "11" and d != 0):
					ans.append(i+1)
					d -= 1
			print(*ans)
			exit(0)
print(-1)