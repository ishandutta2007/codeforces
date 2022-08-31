def mem(ind,j):
	if(ind == n):
		return 0
	if(dp2[ind][j] != -1):
		return dp2[ind][j]
	ans = 0
	for i in range(min(j,sz[ind])+1):
		ans = max(ans,dp[ind][i]+mem(ind+1,j-i))
	dp2[ind][j] = ans
	return ans

n,m = map(int,input().split())
sz = [0 for i in range(n)]
dp = []
for y in range(n):
	a = list(map(int,input().split()))
	sz[y] = a[0]
	pre = [a[1]]
	for i in range(2,sz[y]+1):
		pre.append(a[i]+pre[-1])
	s = sum(a[1:])
	dp1 = [0 for j in range(sz[y]+1)]
	dp1[sz[y]] = s
	for i in range(sz[y]):
		for j in range(i,sz[y]):
			if(i != 0): dp1[sz[y]-(j-i+1)] = max(dp1[sz[y]-(j-i+1)],s-pre[j]+pre[i-1])
			else: dp1[sz[y]-(j-i+1)] = max(dp1[sz[y]-(j-i+1)],s-pre[j])
	dp.append(dp1)
dp2 = [[-1 for i in range(m+1)] for j in range(n)]
print(mem(0,m))