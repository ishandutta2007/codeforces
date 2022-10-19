import sys
input = sys.stdin.readline

def main():
    n, k = map(int, input().split())
    alst = list(map(int, input().split()))
    inf = -10 ** 8
    dp = [[inf] * (n + 1) for _ in range(n + 1)]
    dp[0][0] = 0
    for i, a in enumerate(alst, 1):
        for j in range(n + 1):
            dp[i][j] = dp[i - 1][j]
            if j != 0:
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1])
                if a == j:
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1)
    #print(dp[-1])
    for i in range(n, k - 1, -1):
        if dp[-1][i] >= k:
            print(n - i)
            return
    print(-1)
    
for _ in range(int(input())):
    main()