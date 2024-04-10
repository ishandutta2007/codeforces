n = list(map(int,raw_input()))
dp = [[1] * 10]
for i in range(1, len(n)):
    dp.append([0] * 10)
    for j in range(10):
        x = j + n[i]
        dp[i][x // 2] += dp[i - 1][j]
        if x % 2:
            dp[i][x // 2 + 1] += dp[i - 1][j]
print(sum(dp[-1]) - all(abs(n[i] - n[i - 1]) <= 1 for i in range(1, len(n))))