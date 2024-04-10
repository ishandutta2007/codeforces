import sys
input = sys.stdin.readline
from heapq import *

def main():
    n, m, x = map(int, input().split())
    hlst = list(map(int, input().split()))
    hq = [(0, i) for i in range(1, m + 1)]
    ans = [-1] * n
    print("YES")
    for i, h in enumerate(hlst):
        t, j = heappop(hq)
        t += h
        ans[i] = j
        heappush(hq, (t, j))
    print(*ans)
        
    

for _ in range(int(input())):
    main()