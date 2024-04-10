n, m = map(int, input().split())
a = []
for i in range(n):
    a.append([])

u = [False] * n
for i in range(m):
    x, y = map(int, input().split())
    x -= 1
    y -= 1
    a[y].append(x)
    a[x].append(y)
ans = 0
for j in range(n):
    if u[j]:
        continue
    q = []
    i = 0
    q.append(j)
    u[j] = True
    s = 0
    h = 0
    while i < len(q):
        v = q[i]
        i += 1
        s = max(s, len(a[v]))
        h += len(a[v])
        for x in a[v]:
            if not u[x]:
                u[x] = True
                q.append(x)
    if h == 2 * len(q) and s == 2 and len(q) > 2:
        ans += 1
print(ans)