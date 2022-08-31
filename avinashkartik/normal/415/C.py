from collections import *
n,k = list(map(int,input().split()))
if(n == 1):
	if(k == 0): print(1)
	else: print(-1)
	exit(0)
ct = k-(n-2)//2
if(ct <= 0):
	print(-1)
	exit(0)
print(ct,2*ct,end = " ")
j = 1
for i in range(n-2):
	if(j == ct): j += 1
	if(j == 2*ct): j += 1
	print(j,end = " ")
	j += 1
print()