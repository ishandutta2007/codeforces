import sys
input = sys.stdin.readline

def main():
    a, n, m = map(int, input().split())
    imos = [0] * (a + 1)
    for _ in range(n):
        l, r = map(int, input().split())
        for k in range(l, r):
            imos[k] += 1
    amb = [None] * (a + 1)
    W = [0] * (m + 1)
    for i in range(1, m + 1):
        x, p = map(int, input().split())
        W[i] = p
        if amb[x] is None or amb[x][0] > p:
            amb[x] = (p, i)
    
    inf = 1 << 60
    dp = [[inf] * (m + 1) for _ in range(a + 1)]
    dp[0][0] = 0
    for i in range(a + 1):
        for j in range(1, m + 1):
            dp[i][0] = min(dp[i][0], dp[i][j])
        if amb[i]:
            j = amb[i][1]
            dp[i][j] = min(dp[i][j], dp[i][0])
        if i != a:
            for j in range(1, m + 1):
                dp[i + 1][j] = dp[i][j] + W[j]
            if imos[i] == 0:
                dp[i + 1][0] = dp[i][0]
    if dp[-1][0] == inf:
        print(-1)
    else:
        print(dp[-1][0])
    
    
    
for _ in range(1):
    main()