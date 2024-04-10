a, b, c, n = map(int, input().split())
s = a + b - c
if s >= n or a < c or b < c:
    print(-1)
else:
    print(n - s)