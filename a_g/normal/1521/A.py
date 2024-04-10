import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
    a, b = I()
    if b == 1:
        print("NO")
    else:
        print("YES")
        print(a, (2*b-1)*a, 2*b*a)