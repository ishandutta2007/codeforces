import sys
input = sys.stdin.readline
from heapq import *

def main():
    n, m = map(int, input().split())
    sdc = [list(map(int, input().split())) for _ in range(m)]
    ans = [0] * n
    add = [[] for _ in range(n)]
    se = set()
    for i in range(m):
        sdc[i][0] -= 1
        sdc[i][1] -= 1
        s, d, c = sdc[i]
        if d in se:
            print(-1)
            return
        se.add(d)
        add[s].append((i + 1, c, d))
    hq = []
    for i in range(n):
        for j, c, d in add[i]:
            for _ in range(c):
                heappush(hq, (d, j))
        if i in se:
            ans[i] = m + 1
        elif hq:
            d, j = heappop(hq)
            if d < i:
                print(-1)
                return
            ans[i] = j
    if hq:
        print(-1)
    else:
        print(*ans)
                
    
for _ in range(1):
    main()