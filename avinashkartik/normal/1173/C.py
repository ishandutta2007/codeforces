from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
n = int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
p = [0 for i in range(n+1)]

for i in range(n):
	p[b[i]] = i+1
if(p[1]):
	i = 2
	while(i <= n and p[i] == p[1]+i-1):
		i+=1
	if(p[i-1] == n):
		j=i
		while(j <= n and p[j] <= j-i):
			j += 1
		if(j > n):
			print(n-i+1)
			exit(0)
ans = 0
for i in range(1,n+1):
	ans = max(ans,p[i]-i+1+n)
print(ans)