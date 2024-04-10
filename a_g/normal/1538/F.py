import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

def solve(l, r):
    if l == r:
        return 0
    return r-l+solve(l//10, r//10)

t, = I()
for _ in range(t):
    l, r = I()
    print(solve(l, r))