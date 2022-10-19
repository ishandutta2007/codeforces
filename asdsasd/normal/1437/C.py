import sys
input = sys.stdin.readline

def main():
    n = int(input())
    tlst = list(map(int, input().split()))
    tlst.sort()
    inf = 10 ** 20
    dp = [[inf for _ in range(2 * n)] for _ in range(n)]
    dp[0][0] = tlst[0]
    for i in range(1, 2 * n):
        dp[0][i] = min(dp[0][i - 1], abs(tlst[0] - i))
    for i in range(1, n):
        for j in range(i + 1, 2 * n):
            dp[i][j] = min(dp[i][j - 1], dp[i - 1][j - 1] + abs(tlst[i] - j))
    print(dp[-1][-1])
    
for _ in range(int(input())):
    main()