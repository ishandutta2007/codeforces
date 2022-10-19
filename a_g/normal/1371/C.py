import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
    a, b, n, m = I()
    print("Yes" if a+b>=m+n and m<=min(a, b) else "No")