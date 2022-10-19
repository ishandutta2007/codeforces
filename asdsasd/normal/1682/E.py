import sys
input = sys.stdin.readline

class UnionFind:
    def __init__(self, n):
        self.n = n
        self.parents = [-1] * n
        self.group = n

    def find(self, x):
        if self.parents[x] < 0:
            return x
        else:
            self.parents[x] = self.find(self.parents[x])
            return self.parents[x]

    def union(self, x, y):
        x = self.find(x)
        y = self.find(y)

        if x == y:
            return
        self.group -= 1
        if self.parents[x] > self.parents[y]:
            x, y = y, x

        self.parents[x] += self.parents[y]
        self.parents[y] = x

    def size(self, x):
        return -self.parents[self.find(x)]

    def same(self, x, y):
        return self.find(x) == self.find(y)

    def members(self, x):
        root = self.find(x)
        return [i for i in range(self.n) if self.find(i) == root]

    def roots(self):
        return [i for i, x in enumerate(self.parents) if x < 0]

    def group_count(self):
        return self.group

    def all_group_members(self):
        dic = {r:[] for r in self.roots()}
        for i in range(self.n):
            dic[self.find(i)].append(i)
        return dic

    def __str__(self):
        return '\n'.join('{}: {}'.format(r, self.members(r)) for r in self.roots())

def scc(N, G):
    order = []
    used = [False]*N
    group = [None]*N
    RG = [[] for _ in range(N)]
    for i in range(N):
        for j in G[i]:
            RG[j].append(i)
    
    def dfs(pos):
        stack = [pos, ~pos]
        while stack:
            pos = stack.pop()
            if pos < 0:
                pos = ~pos
                if used[pos]:
                    stack.pop()
                    continue
                used[pos] = True
                for npos in G[pos]:
                    if not used[npos]:
                        stack.append(npos)
                        stack.append(~npos)
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

def construct(N, G, label, group):
    G0 = [[] for _ in range(label)]
    GP = [[] for _ in range(label)]
    for v in range(N):
        lbs = group[v]
        for w in G[v]:
            lbt = group[w]
            if lbs == lbt:
                continue
            G0[lbs].append(lbt)
        GP[lbs].append(v)
    return G0, GP

def solve():
    n, m = map(int, input().split())
    P = list(map(int, input().split()))
    edges = [[] for _ in range(n + 1)]
    UF = UnionFind(n + 1)
    for i in range(m):
        x, y = map(int, input().split())
        if x > y:
            x, y = y, x
        UF.union(x, y)
        edges[x].append((y, i))
        edges[y].append((x, i))
    for r in UF.roots():
        if r != 0:
            edges[0].append((r, -1))

    dist = [-1] * (n + 1)
    parent = [-1] * (n + 1)
    pind = [-1] * (n + 1)
    dist[0] = 0
    stack = [0]
    while stack:
        pos = stack.pop()
        for npos, i in edges[pos]:
            if dist[npos] != -1:
                continue
            dist[npos] = dist[pos] + 1
            parent[npos] = pos
            pind[npos] = i
            stack.append(npos)
    
    edges2 = [[] for _ in range(m)]
    for u, v in enumerate(P, 1):
        L = []
        R = []
        while u != v:
            if dist[u] > dist[v]:
                L.append(pind[u])
                u = parent[u]
            elif dist[v] > dist[u]:
                R.append(pind[v])
                v = parent[v]
            else:
                L.append(pind[u])
                u = parent[u]
                R.append(pind[v])
                v = parent[v]
        L += R[::-1]
        le = len(L)
        for i in range(le - 1):
            edges2[L[i]].append(L[i + 1])
    label, group = scc(m, edges2)
    ans = [-1] * m
    for i, g in enumerate(group, 1):
        ans[g] = i
    print(*ans)
        
    
for _ in range(1):
    solve()