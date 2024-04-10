import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
    n, = I()
    a = I()
    x = a.index(min(a))
    y = a.index(max(a))
    l = min(x, y)
    r = max(x, y)
    print(min(r+1, n-l, l+1+n-r))