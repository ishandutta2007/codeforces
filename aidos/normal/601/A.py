n, m = map(int, input().split())
a = []
for i in range(n):
    a.append([0] * n)

for i in range(m):
    x, y = map(int, input().split())
    x -= 1
    y -= 1
    a[x][y] = 1
    a[y][x] = 1
q = []
r = 0
q.append(0)
u = [-1] * n
u[0] = 0
while r < len(q):
    v = q[r]
    r += 1
    for i in range(n):
        if u[i] == -1 and a[v][i] != a[0][n-1]:
            u[i] = u[v] + 1
            q.append(i)
print(u[n-1])