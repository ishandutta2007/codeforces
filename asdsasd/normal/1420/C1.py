import sys
input = sys.stdin.readline
from bisect import bisect_right

bin_s = [1]
while bin_s[-1] <= 10 ** 9:
    bin_s.append(bin_s[-1] * 2)


def main():
    n, q = map(int, input().split())
    alst = list(map(int, input().split()))
    dp = [[-1, -1] for _ in range(n)]
    dp[0] = [alst[0], 0]
    for i, a in enumerate(alst[1:], start = 1):
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + a)
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - a)
    print(max(dp[-1]))
    

for _ in range(int(input())):
    main()