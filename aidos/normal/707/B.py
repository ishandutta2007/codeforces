n, m, k = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(m)]
u = [0] * (n+1)
b = []
if k > 0:
    b = map(int, input().split())
for x in b:
    u[x] = 1
c = []
for x in a:
    if u[x[0]] + u[x[1]] == 1:
        c.append(x[2])
if len(c) == 0:
    print(-1)
else:
    print(min(c))