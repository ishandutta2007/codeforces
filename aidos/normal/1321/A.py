

def solve():
    n = int(input())
    r = list(map(int, input().split()))
    b = list(map(int, input().split()))
    x, y, z = 0, 0, 0
    for i in range(n):
        if r[i] > 0 and b[i] > 0:
            x += 1
        elif r[i] > 0:
            y += 1
        elif b[i] > 0:
            z += 1
    if y == 0:
        print(-1)
        return
    print(z//y + 1)





t = 1#int(input())
for i in range(t):
    solve()