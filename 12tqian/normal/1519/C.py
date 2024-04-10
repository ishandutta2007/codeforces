import sys
import math

input = sys.stdin.readline

tt = int(input())

for _ in range(tt):
    n = int(input())
    u = list(map(int, input().split()))
    s = list(map(int, input().split()))
    loc = [[] for _ in range(n)]
    for i in range(n):
        u[i] -= 1
        loc[u[i]].append(s[i])
    ans = [0] * (n + 1)
    for i in range(n):
        loc[i].sort()
        loc[i].reverse()
        pre = [0] * len(loc[i])
        for j in range(len(loc[i])):
            if j == 0:
                pre[j] = loc[i][j]
            else:
                pre[j] = pre[j - 1] + loc[i][j]
        def sum(l, r):
            if l > r:
                return 0
            res = pre[r]
            if l > 0: 
                res -= pre[l - 1]
            return res
        for k in range(1, len(loc[i]) + 1):
            add = sum(0, len(loc[i]) - 1)
            add -=  sum(len(loc[i]) // k * k, len(loc[i]) - 1)
            ans[k] += add
    for i in range(1, n + 1):
        print(ans[i], end = " ")
    print()