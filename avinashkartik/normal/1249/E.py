n,k = map(int,input().split())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
dp = [[0,0] for i in range(n)]
dp[0][0] = k
ans = [0 for i in range(n)]
for i in range(0,n-1):
    dp[i+1][0] = min(dp[i][0],dp[i][1] + k) + b[i]
    dp[i+1][1] = min(dp[i][0],dp[i][1]) + a[i]
    ans[i+1] = min(dp[i+1][0],dp[i+1][1])
for i in ans:
    print(i,end = " ")