import sys
input = sys.stdin.readline
from collections import deque

def solve():
    n, x = map(int, input().split())
    se = set()
    l = 10 ** (n - 1)
    r = 10 ** n
    queue = deque()
    queue.append((x, 0))
    while queue:
        x, d = queue.popleft()
        d += 1
        se2 = set(map(int, str(x)))
        for y in se2:
            nx = x * y
            if l <= nx < r:
                print(d)
                return
            elif r <= x:
                continue
            if nx in se:
                continue
            se.add(nx)
            queue.append((nx, d))
    print(-1)

    

for _ in range(1):
    solve()