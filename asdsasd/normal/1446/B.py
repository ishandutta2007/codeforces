import sys
input = sys.stdin.readline

def main():
    n, m = map(int, input().split())
    A = input().strip()
    B = input().strip()
    dp = [[0 for _ in range(m + 1)] for _ in range(n + 1)]
    ans = 0
    for i, a in enumerate(A, 1):
        for j, b in enumerate(B, 1):
            if a == b:
                dp[i][j] = dp[i - 1][j - 1] + 2
            else:
                dp[i][j] = max(max(dp[i - 1][j], dp[i][j - 1]) - 1, 0)
            ans = max(ans, dp[i][j])
    print(ans)
    
for _ in range(1):
    main()