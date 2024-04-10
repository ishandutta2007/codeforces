import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
    n, = I()
    a = I()
    s = sum(a)
    if s%n != 0:
        print(-1)
        continue
    print(len([x for x in a if x > s//n]))