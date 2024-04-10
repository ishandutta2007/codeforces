
dp = [0] * 1000

for i in range(1, len(dp)):
    dp[i] = 10**18
    if i >= 6:
        dp[i] = min(dp[i-6]+15, dp[i])
    if i >= 8:
        dp[i] = min(dp[i-8]+20, dp[i])
    if i >= 10:
        dp[i] = min(dp[i-10]+25, dp[i])

for i in range(len(dp)-2, -1, -1):
    dp[i] = min(dp[i], dp[i+1])


def solve():
    n = int(input())
    if n < 240:
        print(dp[n])
    else:
        x = n % 120 + 120
        print(dp[x] + 300 * ((n-120)//120))

t = int(input())
for i in range(t):
    solve()