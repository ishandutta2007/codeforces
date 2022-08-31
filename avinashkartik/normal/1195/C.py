n = int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))

dp = [[0,0] for i in range(n)]
dp[0][0] = a[0]
dp[0][1] = b[0]

if(n > 1):
    dp[1][0] = b[0] + a[1]
    dp[1][1] = a[0] + b[1]

    for i in range(2,n):
        #print(dp)
        dp[i][0] = max(dp[i-1][1],dp[i-2][1]) + a[i]
        dp[i][1] = max(dp[i-1][0],dp[i-2][0]) + b[i]

print(max(dp[n-1][0],dp[n-1][1]))