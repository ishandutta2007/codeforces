t = int(input())
for _ in range(t):
    b, p, f = map(int, input().split())
    b //= 2
    h, c = map(int, input().split())
    if h < c:
        h, c = c, h
        p, f = f, p
    x = min(b, p)
    print(x * h + min(b-x, f) * c)