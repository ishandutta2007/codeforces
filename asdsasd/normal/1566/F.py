import sys
input = sys.stdin.readline
from bisect import bisect_left, bisect_right


def main():
    n, m = map(int, input().split())
    alst = list(map(int, input().split()))
    alst.sort()
    lr = []
    for _ in range(m):
        l, r = map(int, input().split())
        if bisect_left(alst, l) == bisect_right(alst, r):
            lr.append((l, r))
    alst = [-10 ** 20] + alst + [10 ** 20]
    inf = 10 ** 20
    dp = [[inf, inf] for _ in range(n + 2)]
    dp[0] = [0, 0]
    p = 0
    lr.sort()
    l = len(lr)
    for i, a in enumerate(alst[1:], 1):
        lst = []
        while p < l and lr[p][0] < a:
            lst.append(lr[p])
            p += 1
        if not lst:
            dp[i][0] = min(dp[i - 1])
            dp[i][1] = min(dp[i - 1])
            continue
        min_ = [alst[i]]
        for _, r in lst[::-1]:
            min_.append(min(min_[-1], r))
        min_ = min_[::-1]
        l_s = [alst[i - 1]] + [ll for ll, _ in lst]
        a0 = alst[i - 1]
        a1 = alst[i]
        for ll, m in zip(l_s, min_):
            dp[i][0] = min(dp[i][0], dp[i - 1][0] + ll - a0 + (a1 - m) * 2, dp[i - 1][1] + (ll - a0) * 2 + (a1 - m) * 2)
            dp[i][1] = min(dp[i][1], dp[i - 1][0] + ll - a0 + a1 - m, dp[i - 1][1] + (ll - a0) * 2 + a1 - m)
    print(min(dp[-1]))
        
        
    
    
for _ in range(int(input())):
    main()