import sys
from math import gcd
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
    n, = I()
    a = I()
    b = []
    g = max(a)
    b.append(g)
    a.remove(g)
    for _ in range(n-1):
        m = max(a, key = lambda v: gcd(v, g))
        b.append(m)
        a.remove(m)
        g = gcd(g, m)
    print(*b)