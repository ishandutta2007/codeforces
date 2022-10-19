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
from heapq import *
from collections import deque

class HopCroftKarp:
    def __init__(self, n, m):
        self.n = n
        self.m = m
        self.G = [[] for _ in range(n)]
        self.RG = [[] for _ in range(m)]
        self.match_l = [-1] * n
        self.match_r = [-1] * m
        self.used = [0] * n
        self.time_stamp = 0

    def add_edges(self, u, v):
        self.G[u].append(v)

    def _build_argument_path(self):
        queue = deque()
        self.dist = [-1] * self.n
        for i in range(self.n):
            if self.match_l[i] == -1:
                queue.append(i)
                self.dist[i] = 0
        while queue:
            a = queue.popleft()
            for b in self.G[a]:
                c = self.match_r[b]
                if c >= 0 and self.dist[c] == -1:
                    self.dist[c] = self.dist[a] + 1
                    queue.append(c)

    def _find_min_dist_argument_path(self, a):
        self.used[a] = self.time_stamp
        for b in self.G[a]:
            c = self.match_r[b]
            if c < 0 or (self.used[c] != self.time_stamp and self.dist[c] == self.dist[a] + 1 and self._find_min_dist_argument_path(c)):
                self.match_r[b] = a
                self.match_l[a] = b
                return True
        return False


    def max_matching(self):
        while 1:
            self._build_argument_path()
            self.time_stamp += 1
            flow = 0
            for i in range(self.n):
                if self.match_l[i] == -1:
                    flow += self._find_min_dist_argument_path(i)
            if flow == 0:
                break
        ret = []
        for i in range(self.n):
            if self.match_l[i] >= 0:
                ret.append((i, self.match_l[i]))
        return ret

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

def contract(deg, k):
    hq = []
    for i, d in enumerate(deg):
        hq.append([d, i])
    heapify(hq)
    UF = UnionFind(len(deg))
    while len(hq) >= 2:
        p = heappop(hq)
        q = heappop(hq)
        if p[0] + q[0] > k:
            continue
        p[0] += q[0]
        UF.union(p[1], q[1])
        heappush(hq, p)
    return UF

def build_k_regular_graph(n, m, A, B):
    dega = [0] * n
    degb = [0] * m
    for a in A:
        dega[a] += 1
    for b in B:
        degb[b] += 1
    K = max(*dega, *degb)

    UFa = contract(dega, K)
    ida = [-1] * n
    pa = 0
    for i in range(n):
        if UFa.find(i) == i:
            ida[i] = pa
            pa += 1

    UFb = contract(degb, K)
    idb = [-1] * m
    pb = 0
    for i in range(m):
        if UFb.find(i) == i:
            idb[i] = pb
            pb += 1
    

    
    p = max(pa, pb)
    dega = [0] * p
    degb = [0] * p

    C = []
    D = []
    for i in range(len(A)):
        u = ida[UFa.find(A[i])]
        v = idb[UFb.find(B[i])]
        C.append(u)
        D.append(v)
        dega[u] += 1
        degb[v] += 1
    j = 0
    for i in range(p):
        while dega[i] < K:
            while degb[j] == K:
                j += 1
            C.append(i)
            D.append(j)
            dega[i] += 1
            degb[j] += 1

    return K, p, C, D


def EdgeColoring(a, b, A, B):
    K, n, A, B = build_k_regular_graph(a, b, A, B)

    ord = [i for i in range(len(A))]
    ans = []

    def euler_trail(ord):
        V = 2 * n
        G = [[] for _ in range(V)]
        m = 0
        for i in ord:
            G[A[i]].append((B[i] + n, m))
            G[B[i] + n].append((A[i], m))
            m += 1
        used_v = [0] * V
        used_e = [0] * m
        ans = []
        for i in range(V):
            if used_v[i]:
                continue
            st = []
            ord2 = []
            st.append((i, -1))
            while st:
                id_ = st[-1][0]
                used_v[id_] = True
                if len(G[id_]) == 0:
                    ord2.append(st[-1][1])
                    st.pop()
                else:
                    e = G[id_][-1]
                    G[id_].pop()
                    if used_e[e[1]]:
                        continue
                    used_e[e[1]] = True
                    st.append(e)
            ord2.pop()
            ord2 = ord2[::-1]
            ans += ord2
        for i, a in enumerate(ans):
            ans[i] = ord[a]
        return ans
    
    def rec(ord, K):
        if K == 0:
            return
        elif K == 1:
            ans.append(ord)
            return
        elif K & 1:
            G = HopCroftKarp(n, n)
            for i in ord:
                G.add_edges(A[i], B[i])
            G.max_matching()
            lst = []
            ans.append([])
            for i in ord:
                if G.match_l[A[i]] == B[i]:
                    G.match_l[A[i]] = -1
                    ans[-1].append(i)
                else:
                    lst.append(i)
            rec(lst, K - 1)
        else:
            path = euler_trail(ord)
            L = []
            R = []
            for i, p in enumerate(path):
                if i & 1:
                    L.append(p)
                else:
                    R.append(p)
            rec(L, K // 2)
            rec(R, K // 2)
    rec(ord, K)
    return K, ans

def solve():
    a, b, m = map(int, input().split())
    A = [-1] * m
    B = [-1] * m
    for i in range(m):
        A[i], B[i] = map(int, input().split())
        A[i] -= 1
        B[i] -= 1
    
    K, ans = EdgeColoring(a, b, A, B)
    color = [-1] * m
    for i in range(len(ans)):
        for j in ans[i]:
            if j < m:
                color[j] = i + 1
    print(K)
    print(*color)
    

for _ in range(1):
    solve()