import sys
input = sys.stdin.readline

def main():
    S = input().strip()
    inf = 10 ** 10
    n = len(S)
    dp = [[-inf] * 3 for _ in range(n + 1)]
    dp[0][0] = 0
    for i, s in enumerate(S, 1):
        s = int(s) % 3
        for j in range(3):
            dp[i][(s + j) % 3] = dp[i - 1][j]
        dp[i][0] += 1
        dp[i][0] = max(dp[i])
        
    print(max(dp[-1]))    
    
    
for _ in range(1):
    main()