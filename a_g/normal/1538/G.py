import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

def check(x, y, a, b, z):
    x -= z*a
    y -= z*a
    if x < 0 or y < 0:
        return False
    if a == b:
        return True
    return x//(b-a)+y//(b-a) >= z

t, = I()
for _ in range(t):
    x, y, a, b = I()
    if a > b:
        a, b = b, a
    low = 0
    high = x+y
    while high-low > 1:
        mid = (low+high)//2
        if check(x, y, a, b, mid):
            low = mid
        else:
            high = mid
    print(low)