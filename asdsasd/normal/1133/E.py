import sys
input = sys.stdin.readline
from math import gcd

def main():
    n, k = map(int, input().split())
    A = list(map(int, input().split()))
    A.sort()
    dp = [[0] * (k + 1) for _ in range(n + 1)]
    l = 0
    for r, a in enumerate(A, 1):
        while A[l] + 5 < a:
            l += 1
        for i in range(k + 1):
            dp[r][i] = dp[r - 1][i]
            if i != 0:
                dp[r][i] = max(dp[r][i], dp[l][i - 1] + r - l)
    print(max(dp[-1]))
            
    
for _ in range(1):
    main()