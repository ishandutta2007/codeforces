from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)

def check(ch):
	if(ch > n): return 0
	if(ch %2 == 0):
		if(ch == n): return 1
		else: 
			st = 4
			ans = 2
	else:
		st = 2
		ans  = 1
	ch *= 2
	while(ch < n):
		if(ch > n + 1 - st):
			ans += n+1-ch
			break
		else:
			ans += st
		st *= 2
		if(ch > n - ch):
			break
		else:
			ch *= 2
	return ans


mod = 10**9 + 7
n,x = map(int,input().split())

l = 1
r = n
ans1 = 0
while(r >= l):
	mid = (r+l)//2
	mid *= 2
	if(check(mid) >= x):
		l = mid//2 + 1
		ans1 = mid
	else:
		r = mid//2 - 1
	#print(mid,check(mid))
l = 1
r = n
ans2 = 0
while(r >= l):
	mid = (r+l)//2
	mid = mid*2-1
	if(check(mid) >= x):
		l = (mid+1)//2 + 1
		ans2 = mid
	else:
		r = (mid+1)//2 - 1
	#print(mid,check(mid))
print(max(ans1,ans2))