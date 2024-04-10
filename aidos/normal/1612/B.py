

def solve():
    n, a, b = map(int, input().split())
    x, y, z = [], [], []
    for i in range(1, n + 1):
        if i == a or i > b:
            if i < a:
                print(-1)
                return
            x.append(i)
        elif i == b or i < a:
            if i > b:
                print(-1)
                return
            y.append(i)
        else:
            z.append(i)
    if len(x) > n//2 or len(y) > n//2:
        print(-1)
        return
    print(' '.join(map(str, x + z + y)))





t = int(input())
for i in range(t):
    solve()