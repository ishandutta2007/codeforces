n = int(input())
arr = sorted((v,i) for i,v in enumerate(map(int, input().split(' '))))
ans = [0] * n
if n == 3:
    print(arr[2][0] - arr[0][0], 1)
    for i in n:
        ans[i] = i
elif n == 4:
    print(arr[3][0] - arr[0][0], 1)
    for i in n:
        ans[i] = i
else:
    INF = 1000000000000000000
    dp = [0,INF,INF,arr[2][0]-arr[0][0],arr[3][0]-arr[0][0]]
    for i in range(4, n):
        dp.append(min(dp[i-2]+arr[i][0]-arr[i-2][0],dp[i-3]+arr[i][0]-arr[i-3][0],dp[i-4]+arr[i][0]-arr[i-4][0]))
    cnt, ls = 1, n
    for i in range(n, 0, -1):
        ans[arr[i-1][1]] = cnt
        if dp[i-1] + arr[ls-1][0] - arr[i-1][0] == dp[ls] and ls - i > 1:
            ls = i - 1
            cnt += 1
    print(dp[n], cnt-1)
print(*ans)