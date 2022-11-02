a, b, c, d, e, f = [int(input()) for _ in range(6)]
y = min(b, c, d)
x = min(a, d)
if e < f:
    x, y = y, x
    e, f = f, e
ans = x * e + min((d-x), y) * f
print(ans)