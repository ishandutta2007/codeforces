import sys
input = sys.stdin.readline
from heapq import *

def main():
    input()
    n, m = map(int, input().split())
    dic = {}
    for i in range(n):
        T = input().strip()
        for j in range(m - 1):
            dic[T[j:j+2]] = (j + 1, j + 2, i + 1)
            if j != m - 2:
                dic[T[j:j+3]] = (j + 1, j + 3, i + 1)
    S = input().strip()
    dp = [False] * (m + 1)
    dp[0] = True
    bef = [None] * (m + 1)
    for i in range(2, m + 1):
        if dp[i - 2] and S[i - 2:i] in dic:
            bef[i] = (i - 2, S[i - 2:i])
            dp[i] = True
        elif i != 2 and dp[i - 3] and S[i - 3:i] in dic:
            bef[i] = (i - 3, S[i - 3:i])
            dp[i] = True
    if not dp[-1]:
        print(-1)
        return
    ans = []
    p = m
    while p != 0:
        p, h = bef[p]
        ans.append(dic[h])
    print(len(ans))
    for row in ans[::-1]:
        print(*row)
    
for _ in range(int(input())):
    main()