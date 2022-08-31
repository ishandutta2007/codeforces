from math import *
t = int(input())
for y in range(t):
	n,g,b = map(int,input().split())
	if(n <= g):
		print(n)
		continue
	x = ceil(n/2)
	a = (ceil(x/g)-1)*b
	#print(a,n//2)
	if(a >= n//2):
		print(a+x)
	else:
		print(x+n//2)