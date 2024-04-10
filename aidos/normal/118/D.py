def calc(a, b, c, x, y, dp, u):
    if b < 0 or c < 0:
        return 0
    if b == 0 and c==0:
        return 1
    
    if u[a][b][c]:
        return dp[a][b][c]
    u[a][b][c] = True
    for i in range(1, x+1):
        dp[a][b][c] = (dp[a][b][c] + calc(1-a, c, b-i, y, x, dp, u)) % (10**8)
    return dp[a][b][c]
    

n, m, x, y = map(int, input().split())

dp = [[],[]]
u = [[], []]
for i in range(103):
    dp[0].append([0] * (103))
    dp[1].append([0] * (103))
    u[0].append([False] * (103))
    u[1].append([False] * (103))

print((calc(0, n, m, x, y, dp, u) + calc(1, m, n, y, x, dp, u)) % (10**8))