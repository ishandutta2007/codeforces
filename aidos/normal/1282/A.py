t = int(input())
for _ in range(t):
    a, b, c, r = map(int, input().split())
    if a > b:
        a, b = b, a
    x = max(c - r, a)
    y = min(c + r, b)
    if x > y:
        print(b - a)
    else:
        print(b-a-(y-x))