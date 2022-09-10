t = int(input())

for case in range(t):
	n = int(input())
	a = [int(s) for s in input().split()]
	dp = [0] * n

	ans = 1
	for i in range(1, n + 1):
		dp[i - 1] += 1
		j = i + i
		while j <= n:
			if(a[j - 1] > a[i - 1]):
				dp[j - 1] = max(dp[j - 1], dp[i - 1])
			j += i
		ans = max(ans, dp[i - 1])
	print(ans)