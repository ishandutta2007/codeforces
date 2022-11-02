n, k =map(int, input().split())

dp = []
k += 1
for j in range(k):
    dp.append([0] * k)

dp[0][0]=1
c = list(map(int, input().split()))
c = sorted(c)
for i in range(n):
    for j in range(k-1, c[i]-1, -1):
        for t in range(j+1):
            if t>=c[i] and dp[j-c[i]][t-c[i]] > 0:
                dp[j][t] = 1
            if dp[j-c[i]][t] > 0:
                dp[j][t] = 1
    if sum(dp[k-1]) == k:
        break
print(sum(dp[k-1]))
for i in range(k):
    if dp[k-1][i]:
        print(i)