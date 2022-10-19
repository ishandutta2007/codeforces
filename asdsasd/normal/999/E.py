# (SCC): GSCC
# : <N>: , <G>: 
# : (<>, <>)
def scc(N, G):
    order = []
    used = [False]*N
    group = [None]*N
    RG = [[] for _ in range(N)]
    for i in range(N):
        for j in G[i]:
            RG[j].append(i)
    
    def dfs(pos):
        stack = [(1, pos), (0, pos)]
        while stack:
            t, pos = stack.pop()
            if t == 0:
                if used[pos]:
                    stack.pop()
                    continue
                used[pos] = True
                for npos in G[pos]:
                    if not used[npos]:
                        stack.append((1, npos))
                        stack.append((0, npos))
            else:
                order.append(pos)

    def rdfs(pos, col):
        stack = [pos]
        group[pos] = col
        used[pos] = True
        while stack:
            pos = stack.pop()
            for npos in RG[pos]:
                if not used[npos]:
                    used[npos] = True
                    group[npos] = col
                    stack.append(npos)
                    
    for i in range(N):
        if not used[i]:
            dfs(i)
    used = [False]*N
    label = 0
    for s in reversed(order):
        if not used[s]:
            rdfs(s, label)
            label += 1
    return label, group

# 
def construct(N, G, label, group):
    G0 = [set() for i in range(label)]
    GP = [[] for i in range(label)]
    for v in range(N):
        lbs = group[v]
        for w in G[v]:
            lbt = group[w]
            if lbs == lbt:
                continue
            G0[lbs].add(lbt)
        GP[lbs].append(v)
    return G0, GP
    
n, m, s = map(int, input().split())
edges = [[] for _ in range(n)]
for _ in range(m):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    edges[a].append(b)
    
label, group = scc(n, edges)
g0, gp = construct(n, edges, label, group)
in_ = [0] * label
for i in range(label):
    for j in g0[i]:
        in_[j] += 1

ans = in_.count(0)
s -= 1
g = group[s]
if in_[g] == 0:
    ans -= 1
print(ans)