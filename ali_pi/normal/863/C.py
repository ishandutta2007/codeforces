f = lambda: list(map(int,input().split()))
g = lambda: [[0] * 4] + [[0] + f() for i in range(3)]
h = lambda x, y: x - 1 == y % 3
t = lambda a, b, u, v: (A[a][b], B[a][b], u + h(a, b), v + h(b, a))
k, a, b = f()
p = 2520
s, d = divmod(k, p)
A, B = g(), g()
u = v = x = y = 0
for j in range(d): a, b, u, v = t(a, b, u, v)
for i in range(p): a, b, x, y = t(a, b, x, y)
print(u + x * s, v + y * s)