import os
import sys
from io import BytesIO, IOBase
 
BUFSIZE = 8192
 
class FastIO(IOBase):
    newlines = 0
 
    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None
 
    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()
 
    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()
 
    def flush(self):
        if self.writable:
            os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)
 
 
class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")
 
 
sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")

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

        for i in range(self.logn):  # depthu
            if (dv - du) >> i & 1:
                v = self.parent[i][v]
        if u == v: return u  # 

        for i in range(self.logn - 1, -1, -1):  # 
            pu, pv = self.parent[i][u], self.parent[i][v]
            if pu != pv:
                u, v = pu, pv
        return self.parent[0][u]

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

def solve():
    n = int(input())
    edges = [[] for _ in range(n)]
    for _ in range(n - 1):
        u, v = map(int, input().split())
        u -= 1
        v -= 1
        edges[u].append(v)
        edges[v].append(u)
    
    lca = LCA(edges)
    L, _ = EulerTour(n, edges)
    Q = int(input())
    for _ in range(Q):
        k = int(input())
        P = list(map(int, input().split()))
        if k == 1:
            print("YES")
            continue
        P = [p - 1 for  p in P]
        P.sort(key=lambda x:L[x])
        tot = 0
        for i in range(k):
            u = P[i - 1]
            v = P[i]
            p = lca.get(u, v)
            tot += lca.depth[u] + lca.depth[v] - 2 * lca.depth[p]
        tot //= 2
        
        u = 0
        ma = 0
        for v in P:
            p = lca.get(u, v)
            d = lca.depth[u] + lca.depth[v] - 2 * lca.depth[p]
            if d > ma:
                ma = d
                uu = v
        u = uu
        ma = 0
        for v in P:
            p = lca.get(u, v)
            d = lca.depth[u] + lca.depth[v] - 2 * lca.depth[p]
            if d > ma:
                ma = d
                uu = v
        v = uu
        p = lca.get(u, v)
        d = lca.depth[u] + lca.depth[v] - 2 * lca.depth[p]
        if d == tot:
            print("YES")
        else:
            print("NO")



    


for _ in range(1):
    solve()