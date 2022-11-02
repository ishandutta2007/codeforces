n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
dp = [0] * (n+1)
d = [0] * (n+1)
dp[1] = a[0]
d[1] = b[0]
for i in range(2, n+1):
    dp[i] = max(d[i-1],d[i-2]) + a[i-1]
    d[i] = max(dp[i-1], dp[i-2]) + b[i-1]
print(max(dp[n], d[n]))