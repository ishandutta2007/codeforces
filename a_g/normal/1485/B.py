import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

n, q, k = I()
a = I()
for _ in range(q):
    l, r = I()
    print(2*(k-r+l-1)-(a[l-1]-1)-(k-a[r-1]))