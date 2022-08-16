def mem(ind,cnt,f):
	if(ind == m):
		if(cnt >= x): return 0
		else: return 1e18
	if(dp[ind][cnt][f] != -1): return dp[ind][cnt][f]
	ans = 1e18
	if(f == 0):
		val = n-ct[ind]
	else:
		val = ct[ind]
	if(cnt >= x):
		ans = min(ans,mem(ind+1,1,f^1)+n-val)
	if(cnt < y):
		ans = min(ans,mem(ind+1,cnt+1,f)+val)
	dp[ind][cnt][f] = ans
	return dp[ind][cnt][f]

n,m,x,y = map(int,input().split())
s = []
for i in range(n):
	s.append(input())
dp = [[[-1,-1] for i in range(y+1)] for j in range(m)]
ct = [0 for i in range(m)]
for i in range(n):
	for j in range(m):
		if(s[i][j] == '.'): 
			ct[j] += 1
print(min(mem(0,0,0),mem(0,0,1)))