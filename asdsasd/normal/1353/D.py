from heapq import *

def solve():
    n = int(input())
    ans = [0 for _ in range(n)]
    hq = [(-n + 1, 0, n - 1)]
    act = 1
    while hq:
        _, l, r = heappop(hq)
        mid = (r + l) // 2
        ans[mid] = act
        act += 1
        if l != mid:
            heappush(hq, (l - mid + 1, l, mid - 1))
        if r != mid:
            heappush(hq, (mid + 1 - r, mid + 1, r))
        
    print(*ans)
    
    
for _ in range(int(input())):
    solve()