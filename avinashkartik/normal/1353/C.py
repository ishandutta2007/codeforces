N = 5*(10**5)+1
dp = [0 for i in range(N)]
dp[1] = 0
for i in range(3,N,2):
	dp[i] = dp[i-2]+8*(i//2)*(i//2)
t = int(input())
for y in range(t):
	n = int(input())
	print(dp[n])