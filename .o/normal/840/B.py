import sys

n, m = map(int, sys.stdin.readline().split())
d = list(map(int, sys.stdin.readline().split()))
gph = [[] for _ in range(n)]

for _ in range(m):
    u, v = map(int, sys.stdin.readline().split())
    u -= 1
    v -= 1
    gph[u].append((v, _))
    gph[v].append((u, _))
    
t = -1
if d.count(1) % 2 == 1:
    if -1 not in d:
        print(-1)
        exit(0)
    t = d.index(-1)

ans = [False] * m
vis = [False] * n
ed = [(-1, -1)] * n
rets = [(d[u] == 1) or (u == t) for u in range(n)]

stk = [[0, iter(gph[0])]]
while len(stk) > 0:
    u = stk[-1][0]
    vis[u] = True
    try:
        while True:
            v, i = next(stk[-1][1])
            if not vis[v]:
                ed[v] = (u, i)
                stk.append([v, iter(gph[v])])
                break
    except StopIteration:
        p, e = ed[u]
        if p >= 0 and rets[u]:
            rets[p] = not rets[p]
            ans[e] = True
        stk.pop()
        pass
    
print(ans.count(True))
print("\n".join([str(i+1) for i in range(m) if ans[i]]))
#1231