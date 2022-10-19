import sys
input = sys.stdin.readline

def main():
    n, m = map(int, input().split())
    grid = [input().strip() for _ in range(n)]
    dp = [[1000 for _ in range(m)] for _ in range(n + 1)]
    for i in range(m):dp[-1][i] = 0
    ans = 0
    for i in range(n - 1, -1, -1):
        total = 0
        for j in range(m):
            if grid[i][j] == "*":
                total += 1
                dp[i][j] = min(dp[i][j], total)
            else:
                total = 0
                dp[i][j] = 0
                
        total = 0
        for j in range(m - 1, -1, -1):
            if grid[i][j] == "*":
                total += 1
                dp[i][j] = min(dp[i][j], total)
            else:
                total = 0
    
    for i in range(n):
        for j in range(m):
            k = 0
            while dp[i + k][j] >= k + 1:
                k += 1
            ans += k
        
    print(ans)

    
for _ in range(int(input())):
    main()