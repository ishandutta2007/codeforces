import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

def ilog(a, b):
    ans = 0
    while a:
        a //= b
        ans += 1
    return ans


t, = I()
for _ in range(t):
    a, b = I()
    ans = 1000
    for j in range(6):
        if b+j == 1:
            continue
        ans = min(ans, j+ilog(a, b+j))
    print(ans)