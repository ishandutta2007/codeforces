
def dfs(v, c, a, u, col):
    q = []
    q.append(v)
    col[v] = c
    u[v] = True
    bad = 0
    r = 0
    while r < len(q):
        v = q[r]
        r += 1
        for to in a[v]:
            if u[to] and col[to] == col[v]:
                bad = 1
            elif not u[to]:
                q.append(to)
                col[to] = 1-col[v]
                u[to] = True
    return bad
            
n, m = map(int, input().split())
a = []
for i in range(n):
    a.append([])
u = [False] * n
col = [0] * n
bad = 0
for i in range(m):
    x, y = map(int, input().split())
    a[x-1].append(y-1)
    a[y-1].append(x-1)
for i in range(n):
    if not u[i]:
        bad += dfs(i, 0, a, u, col)

if bad > 0:
    print(-1)
else:
    print(sum(col))
    for i in range(n):
        if col[i] == 1:
            print(i+1)
    print(n-sum(col))
    for i in range(n):
        if col[i] == 0:
            print(i+1)