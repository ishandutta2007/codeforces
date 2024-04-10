import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
    n, r = I()
    k = min(r, n-1)
    print(k*(k+1)//2+(r>=n))