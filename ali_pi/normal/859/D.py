n = int(input())
m = 1 << n
p = [list(map(int, input().split())) for i in range(m)]
u, x = [1] * m, [0] * m
v, y = u[:], x[:]
for i in range(n):
    d = 1 << i
    for j in range(m):
        s = d * (j // d ^ 1)
        v[j] = u[j] * sum(u[k] * p[j][k] for k in range(s, s + d)) / 100
        y[j] = max(x[s: s + d]) + x[j] + v[j] * d
    u, v, x, y = v, u, y, x
print(max(x))