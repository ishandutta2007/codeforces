from collections import *
n = int(input())
a = list(map(int,input().split()))
c = Counter(a)
f = 1
for v in c.values():
	if v >= (n+1)//2+1:
		f = 0
if(f == 1):
	print("YES")
else:
	print("NO")