import sys, math, itertools, random, bisect
from collections import defaultdict
INF = sys.maxsize
def get_ints(): return map(int, sys.stdin.readline().strip().split())
def get_array(): return list(map(int, sys.stdin.readline().strip().split()))
def input(): return sys.stdin.readline().strip()
mod = 10**9 + 7


for _ in range(int(input())):
    n,m,r1,c1,r2,c2 = get_ints()
    dr = 1
    dc = 1
    r1 -= 1
    c1 -= 1
    r2 -= 1
    c2 -= 1
    ans = 0
    while r1!=r2 and c1!=c2:
        ans += 1
        if r1 + dr >= n: 
            dr = -1
        if r1 + dr < 0:
            dr = 1
        if c1 + dc >= m:
            dc = -1
        if c1 + dc < 0:
            dc = 1
        r1 += dr
        c1 += dc
    print(ans)