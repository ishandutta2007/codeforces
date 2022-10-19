n, k = map(int, input().split())
a = list(map(lambda x: int(x) - 1, input().split()))
dp = [0] * n
for i in range(n):
	if a[i] == -1:
		dp[i] = min(i, k) + min(n - i - 1, k) + 1
	else:
		dp[i] = dp[a[i]] - min(n - a[i] - 1, k) + min(n - i - 1, k) + min(2 * k, i - a[i] - 1) + 1
print(' '.join(list(map(str, dp))))