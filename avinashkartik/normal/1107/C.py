from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
n,k = map(int,input().split())
a = list(map(int,input().split()))
s = input()
i = 0
ans = 0
while(i < n):
	ch = s[i]
	j = i
	while(i < n and s[i] == ch):
		i += 1
	l = a[j:i]
	l.sort(reverse = True)
	m = min(i-j,k)
	ans += sum(l[:m])
print(ans)