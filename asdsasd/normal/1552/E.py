import sys
input = sys.stdin.readline
from heapq import *

def main():
    n, k = map(int, input().split())
    clst = list(map(int, input().split()))
    max_ = (n + k - 1 - 1) // (k - 1)
    cnt = [0] * (n * k)
    aft = [-1] * n
    nex = [-1] * (n * k)
    bef = [-1] * (n * k)
    for i in range(n * k - 1, -1, -1):
        c = clst[i] - 1
        nex[i] = aft[c]
        aft[c] = i
    used = [False] * n
    hq = []
    for i in range(n * k):
        c = clst[i] - 1
        if not used[c]:
            used[c] = True
            j = nex[i]
            bef[j] = i
            heappush(hq, -j)
            for l in range(i, j + 1):
                cnt[l] += 1
        
        while cnt[i] > max_:
            j = -heappop(hq)
            used[clst[j] - 1] = False
            i = bef[j]
            for l in range(i, j + 1):
                cnt[l] -= 1
    ans = [-1] * n
    for h in hq:
        h = -h
        ans[clst[h] - 1] = (bef[h] + 1, h + 1)
    for row in ans:
        print(*row)
            
    
    
        
for _ in range(1):
    main()