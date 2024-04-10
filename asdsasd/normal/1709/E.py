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

def solve():
    n = int(input())
    A = list(map(int, input().split()))
    edges = [[] for _ in range(n)]
    for _ in range(n - 1):
        u, v = map(int, input().split())
        u -= 1
        v -= 1
        edges[u].append(v)
        edges[v].append(u)
    X = [-1] * n
    X[0] = A[0]
    stack = [0]
    route = [0]
    while stack:
        pos = stack.pop()
        for npos in edges[pos]:
            if X[npos] != -1:
                continue
            X[npos] = X[pos] ^ A[npos]
            stack.append(npos)
            route.append(npos)
    
    dp = [set() for _ in range(n)]
    used = [False] * n
    ans = 0
    for pos in route[::-1]:
        used[pos] = True
        dp[pos].add(X[pos])
        for npos in edges[pos]:
            if not used[npos]:
                continue
            if len(dp[npos]) > len(dp[pos]):
                dp[pos], dp[npos] = dp[npos], dp[pos]
            br = False
            for x in dp[npos]:
                if x ^ A[pos] in dp[pos]:
                    dp[pos] = set()
                    ans += 1
                    br = True
                    break
            if br:
                break
            for x in dp[npos]:
                dp[pos].add(x)
    print(ans)
        

    
for _ in range(1):
    solve()