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


MOD = 998244353
N = 200000
fact = [0 for _ in range(N)]
invfact = [0 for _ in range(N)]
fact[0] = 1
for i in range(1, N):
    fact[i] = fact[i - 1] * i % MOD

invfact[N - 1] = pow(fact[N - 1], MOD - 2, MOD)

for i in range(N - 2, -1, -1):
    invfact[i] = invfact[i + 1] * (i + 1) % MOD

def nCk(n, k):
    if k < 0 or n < k:
        return 0
    else:
        return (fact[n] * invfact[k] % MOD) * invfact[n - k] % MOD

def nPk(n, k):
    if k < 0 or n < k:
        return 0
    else:
        return fact[n] * invfact[n - k] % MOD

def nHk(n, k):
    if n == k == 0:
        return 1
    return nCk(n + k - 1, k)



def solve():
    n, k = map(int, input().split())
    P = list(map(int, input().split()))
    child = [[] for _ in range(n)]
    for i, p in enumerate(P, 1):
        child[p - 1].append(i)

    route = [0]
    stack = [0]
    while stack:
        pos = stack.pop()
        for npos in child[pos]:
            route.append(npos)
            stack.append(npos)

    def ok(x):
        if x == 0:
            return False
        ma = [1] * n
        cnt = [0] * n
        for pos in range(n - 1, -1, -1):
            for npos in child[pos]:
                cnt[pos] += cnt[npos]
                ma[pos] = max(ma[pos], ma[npos] + 1)
            if pos != 0 and P[pos - 1] != 1 and ma[pos] == x:
                cnt[pos] += 1
                ma[pos] = -1
        
        return cnt[0] <= k
    
    l = 0
    r = n
    while r - l > 1:
        mid = (l + r) // 2
        if ok(mid):
            r = mid
        else:
            l = mid

    print(r)





for _ in range(int(input())):
    solve()