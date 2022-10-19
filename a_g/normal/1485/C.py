import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
    x, y = I()
    ans = 0
    for k in range(1, 100000):
        if k*(k+2) > x:
            break
        ans += min(y+1, x//k)-min((k+1), y+1)
    print(ans)