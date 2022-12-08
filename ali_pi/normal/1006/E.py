n, q = map(int, input().split())
par = [int(v)-1 for v in input().split()]
chs = [[] for i in range(n)]
for i, p in enumerate(par):
    chs[p].append(i+1)
vis = [0 for _ in range(n)]
bel = [1 for _ in range(n)]
stack = [0]
order = [0]
while stack:
    v = stack[-1]
    if len(chs[v]) == vis[v]:
        if v != 0:
            bel[par[v-1]] += bel[v]
        stack.pop()
        continue
    ch = chs[v][vis[v]]
    vis[v] += 1
    order.append(ch)
    stack.append(ch)
FST = {}
for i, c in enumerate(order):
    FST[c] = i
out = []
for _ in range(q):
    u, k = map(lambda x: int(x) - 1, input().split())
    if k >= bel[u]:
        out.append(-1)
    else:
        out.append(order[FST[u] + k] + 1)
print('\n'.join(map(str, out)))