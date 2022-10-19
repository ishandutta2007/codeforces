import sys
input = sys.stdin.readline
from bisect import bisect_left

def main():
    n, h, l, r = map(int, input().split())
    alst = list(map(int, input().split()))
    dp = [[-10 ** 10] * h for _ in range(n + 1)]
    dp[0][0] = 0
    for i, a in enumerate(alst, 1):
        for j in range(h):
            dp[i][j] = max(dp[i - 1][(j - a) % h], dp[i - 1][(j - a + 1) % h])
            if l <= j <= r:
                dp[i][j] += 1
    print(max(0, max(dp[-1])))
                
    
for _ in range(1):
    main()