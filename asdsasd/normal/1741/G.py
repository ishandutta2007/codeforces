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
from collections import deque
import itertools

def bfs(edges, s):
    n = len(edges)
    dist = [-1] * n
    dist[s] = 0
    queue = deque()
    queue.append(s)
    while queue:
        pos = queue.popleft()
        for npos in edges[pos]:
            if dist[npos] == -1:
                dist[npos] = dist[pos] + 1
                queue.append(npos)
    return dist

def popcount(x):
    x = x - ((x >> 1) & 0x55555555)
    x = (x & 0x33333333) + ((x >> 2) & 0x33333333)
    x = (x + (x >> 4)) & 0x0f0f0f0f
    x += x >> 8
    x += x >> 16
    return x & 0x0000003f

def solve():
    n, m = map(int, input().split())
    edges = [[] for _ in range(n)]
    for _ in range(m):
        u, v = map(int, input().split())
        u -= 1
        v -= 1
        edges[u].append(v)
        edges[v].append(u)

    f = int(input())
    H = list(map(int, input().split()))
    k = int(input())
    P = list(map(int, input().split()))
    H = [h - 1 for h in H]
    P = [p - 1 for p in P]

    d0 = bfs(edges, 0)
    D = [bfs(edges, H[p]) for p in P]

    dp = [popcount(bit) for bit in range(1 << k)]
    
    se_P = set(P)
    for ii, h in enumerate(H):
        if ii in se_P:
            continue
        ndp = dp[:]
        
        for bit in range(1, 1 << k):
            A = []
            for i in range(k):
                if bit >> i & 1:
                    A.append(i)
            
            ok = False
            for B in itertools.permutations(A):
                d = d0[H[P[B[0]]]]
                for i in range(len(B) - 1):
                    d += D[B[i]][H[P[B[i + 1]]]]
                d += D[B[-1]][h]
                if d == d0[h]:
                    ok = True
                    break

            if ok:
                for S in range(1 << k):
                    ndp[S | bit] = min(ndp[S | bit], dp[S])
        dp = ndp
    
    print(dp[-1])

    
for _ in range(int(input())):
    solve()