import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
    n, = I()
    a = I()
    b = []
    for i in range(n//2):
        if a[2*i]+a[2*i+1] == 1:
            b.append(0)
        else:
            b += a[2*i:2*i+2]
    print(len(b))
    print(*b)