from collections import *
from math import *

def ch(mx):
	if(mx > n):
		return 0
	m = l[0]//(1<<(mx-1))
	for i in range(mx):
		m = min(m,l[i]//(1<<(mx-i-1)))
	return m*((1<<mx)-1)

n = int(input())
mx = ceil(log(n,2))
a = list(map(int,input().split()))
c = Counter(a)
l = list(c.values())
l.sort(reverse = True)
n = len(l)
ans = 1
for i in range(1,mx+1):
	ans = max(ans,ch(i))
print(ans)