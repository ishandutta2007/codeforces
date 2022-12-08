import sys
def dfs(u):
    avail[u] = False
    for v in g[u]:
        if avail[v]:
            dfs(v)
    topo.append(u)
sys.setrecursionlimit(6000)
n, m, s = map(int,raw_input().split())
g = [[] for _ in range(n)]
for _ in range(m):
    u, v = map(int,raw_input().split())
    g[u - 1].append(v - 1)
avail, topo = [True] * n, []
for i,a in enumerate(avail):
    if a:
        dfs(i)
avail, res = [True] * n, 0
dfs(s - 1)
for i in reversed(topo):
    if avail[i]:
        res += 1
        dfs(i)
print(res)