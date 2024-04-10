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

class Two_SAT:
    def __init__(self, n):
        self.n = n
        self.G = [[] for _ in range(2 * n)]
    
    # a V B
    # pos_i = True -> a = i
    # pos_i = False -> a = i
    def add_edge(self, i, pos_i, j, pos_j):
        i0 = i
        i1 = i + self.n
        if not pos_i:
            i0, i1 = i1, i0
        j0 = j
        j1 = j + self.n
        if not pos_j:
            j0, j1 = j1, j0
        self.G[i1].append(j0)
        self.G[j1].append(i0)
            
    def const(self):
        _, self.group = scc(2 * self.n, self.G)
    
    def check(self):
        for i in range(self.n):
            if self.group[i] == self.group[i + self.n]:
                return False
        return True
        
    def assign(self):
        ret = [False] * self.n
        for i in range(self.n):
            if self.group[i] > self.group[i + self.n]:
                ret[i] = True
        return ret


def solve():
    n, m, k = map(int, input().split())
    f = lambda x, y: x * (k + 1) + y
    TS = Two_SAT(n * (k + 1))
    for i in range(n):
        TS.add_edge(f(i, 0), False, f(i, 0), False)
        TS.add_edge(f(i, k), True, f(i, k), True)
        for j in range(k):
            TS.add_edge(f(i, j), False, f(i, j + 1), True)
            if i != n - 1:
                TS.add_edge(f(i, j), True, f(i + 1, j), False)

    for _ in range(m):
        const = list(map(int, input().split()))
        if const[0] == 1:
            i, x = const[1:]
            i -= 1
            TS.add_edge(f(i, x - 1), True, f(i, x), False)
        elif const[0] == 2:
            i, j, x = const[1:]
            i -= 1
            j -= 1
            for xx in range(k + 1):
                yy = x - xx - 1
                if 0 <= yy <= k:
                    TS.add_edge(f(i, xx), True, f(j, yy), True)
        else:
            i, j, x = const[1:]
            i -= 1
            j -= 1
            for xx in range(k + 1):
                yy = x - xx - 1
                if 0 <= yy <= k:
                    TS.add_edge(f(i, xx), False, f(j, yy), False)
    TS.const()
    if TS.check():
        ans = [0] * n
        ret = TS.assign()
        for i in range(n):
            for j in range(k + 1):
                if ret[f(i, j)]:
                    ans[i] = j
                    break
        print(*ans)
    else:
        print(-1)
    
    
for _ in range(int(input())):
    solve()