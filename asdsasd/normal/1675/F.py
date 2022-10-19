import sys
input = sys.stdin.readline

def EulerTour(n, edges, root=0):
    L = [-1] * n
    R = [0] * n
    stack = [(root, 1), (root, 0)]
    ind = 0
    while stack:
        pos, t = stack.pop()
        if t == 0:
            L[pos] = ind
            ind += 1
            for npos in edges[pos]:
                if L[npos] != -1:
                    continue
                stack.append((npos, 1))
                stack.append((npos, 0))
        else:
            R[pos] = ind
    
    return L, R

class LCA:
    def __init__(self, G, root=0):
        self.G = G
        self.root = root
        self.n = len(G)
        self.logn = (self.n - 1).bit_length()
        self.depth = [-1 if i != root else 0 for i in range(self.n)]
        self.parent = [[-1] * self.n for _ in range(self.logn)]
        self.dfs()
        self.doubling()

    def dfs(self):
        que = [self.root]
        while que:
            u = que.pop()
            for v in self.G[u]:
                if self.depth[v] == -1:
                    self.depth[v] = self.depth[u] + 1
                    self.parent[0][v] = u
                    que += [v]

    def doubling(self):
        for i in range(1, self.logn):
            for v in range(self.n):
                if self.parent[i - 1][v] != -1:
                    self.parent[i][v] = self.parent[i - 1][self.parent[i - 1][v]]

    def get(self, u, v):
        if self.depth[v] < self.depth[u]:
            u, v = v, u
        du = self.depth[u]
        dv = self.depth[v]

        for i in range(self.logn):
            if (dv - du) >> i & 1:
                v = self.parent[i][v]
        if u == v: return u

        for i in range(self.logn - 1, -1, -1):
            pu, pv = self.parent[i][u], self.parent[i][v]
            if pu != pv:
                u, v = pu, pv
        return self.parent[0][u]

def main():
    input()
    n, k = map(int, input().split())
    x, y = map(int, input().split())
    x -= 1
    y -= 1
    A = list(map(int, input().split()))
    A = [a - 1 for a in A]
    edges = [[] for _ in range(n)]
    for _ in range(n - 1):
        u, v = map(int, input().split())
        u -= 1
        v -= 1
        edges[u].append(v)
        edges[v].append(u)

    L, _ = EulerTour(n, edges)
    lca = LCA(edges)
    A.append(x)
    A.append(y)
    A.sort(key=lambda x:L[x])
    ans = 0
    u = A[-1]
    for v in A:
        p = lca.get(u, v)
        ans += lca.depth[u] + lca.depth[v] - 2 * lca.depth[p]
        u = v
    p = lca.get(x, y)
    ans -= lca.depth[x] + lca.depth[y] - 2 * lca.depth[p]
    print(ans)


for _ in range(int(input())):
    main()