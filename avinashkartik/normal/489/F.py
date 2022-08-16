from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
dp = [[-1 for i in range(505)] for j in range(505)]
def memo(row,z,o):
	if(row == n):
		if(z == 0 and o == 0):
			return 1
		else:
			return 0
	if(dp[z][o] != -1): return dp[z][o]
	
	if(z > 1):
		dp[z][o] += (z*(z-1)//2)*(memo(row+1,z-2,o+2))
		dp[z][o] %= mod
	if(z >= 1 and o >= 1):
		dp[z][o] += (z*o)*(memo(row+1,z-1,o))
		dp[z][o] %= mod
	if(o > 1):
		dp[z][o] += (o*(o-1)//2)*(memo(row+1,z,o-2))
		dp[z][o] %= mod
	#print(row,z,o,dp[z][o])
	dp[z][o] += 1
	dp[z][o] %= mod
	return dp[z][o]%mod

n,m,mod = map(int,input().split())
a = []
for i in range(m):
    s = list(input())
    a.append(s)
#print(a)
ct = [0 for i in range(n)]
for i in range(m):
	for j in range(n):
		if(a[i][j] == '1'):
			ct[j] += 1

z = ct.count(0)
o = ct.count(1)
ans = memo(m,z,o)
print(ans%mod)