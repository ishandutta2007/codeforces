import sys
input = sys.stdin.readline

def main():
    S = input().strip()
    dp = [-1 << 30] * 27
    dp[0] = 0
    for s in S:
        p = ord(s) - 96
        dp[p], dp[0] = max(dp[p], dp[0] + 1), max(dp[0], dp[p] + 1)
    print(len(S) - dp[0])
        
    
    
for _ in range(int(input())):
    main()