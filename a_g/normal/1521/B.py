import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
    n, = I()
    a = I()
    z = min(range(n), key=lambda i: a[i])
    print(n-1)
    for i in range(n):
        if i == z:
            continue
        print(i+1, z+1, a[z] if (i%2 == z%2) else a[z]+1, a[z])