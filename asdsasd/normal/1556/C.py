import sys
input = sys.stdin.readline
from heapq import *

def main():
    n = int(input())
    clst = list(map(int, input().split()))
    ans = 0
    min_ = 0
    hq = []
    now = 0
    for i, c in enumerate(clst):
        if i % 2 == 0:
            now += c
        else:
            pos = now - c
            if pos >= min_:
                ans += c
                add = 1
            else:
                ans += now - min_
                min_ = pos
                add = 0
            while hq:
                if pos <= -hq[0] < now:
                    ans += 1
                    if pos == -hq[0]:
                        add += 1
                    heappop(hq)
                else:
                    break
            for _ in range(add):
                heappush(hq, -pos)
            now = pos
    print(ans)
                    
    
for _ in range(1):
    main()