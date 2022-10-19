import sys
input = sys.stdin.readline

def main():
    n = int(input())
    S = [input().strip() for _ in range(2)]
    l = r = -1
    for i in range(n):
        if S[0][i] == "*" or S[1][i] == "*":
            if l == -1:
                l = i
            r = i
    S = [row[l:r+1] for row in S]
    n = r - l + 1
    dp = [[0] * 2 for _ in range(n)]
    dp[0] = [0, 0]
    if S[0][0] == "*":
        dp[0][1] = 1
    if S[1][0] == "*":
        dp[0][0] = 1
    for i in range(1, n):
        if S[1][i] == "*":
            dp[i][0] = min(dp[i - 1][0] + 2, dp[i - 1][1] + 2)
        else:
            dp[i][0] = min(dp[i - 1][0] + 1, dp[i - 1][1] + 2)
        if S[0][i] == "*":
            dp[i][1] = min(dp[i - 1][0] + 2, dp[i - 1][1] + 2)
        else:
            dp[i][1] = min(dp[i - 1][0] + 2, dp[i - 1][1] + 1)
    print(min(dp[-1]))
        
    
for _ in range(int(input())):
    main()