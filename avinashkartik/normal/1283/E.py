from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
n = int(input())
a = list(map(int,input().split()))
ct = [0 for i in range(n+2)]
for i in a:
	ct[i] += 1
dp = [0 for i in range(n+2)]
ans = 0
i = 1
while(i <= n):
	if(ct[i] == 0):
		i += 1
		continue
	ans += 1
	i += 3

dp = [0 for i in range(n+2)]
ans2 = 0
#print(ct)
for i in range(1,n+1):
	if(ct[i] == 0): continue
	if(ct[i-1] == 0):
		dp[i-1] = 1
		ct[i] -= 1
	if(ct[i] == 0): continue
	if(ct[i] == 1):
		dp[i] = 1
		continue
	ct[i+1] += 1
	dp[i+1] = 1
	if(ct[i] != 0):
		dp[i] = 1
#print(dp)
for i in range(n+2):
	ans2 += dp[i]
print(ans,ans2)