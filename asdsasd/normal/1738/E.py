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

import random
xor = random.randrange(1, 1 << 60)

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
    n = int(input())
    A = list(map(int, input().split()))
    tot = sum(A)
    if tot == 0:
        print(pow(2, n - 1, MOD))
        return
    
    L = {}
    R = {}
    s = 0
    for l in range(n):
        s += A[l]
        if s * 2 >= tot:
            break
        L[s ^ xor] = L.get(s ^ xor, 0) + 1

    s = 0
    for r in range(n - 1, -1, -1):
        s += A[r]
        if s * 2 >= tot:
            break
        R[s ^ xor] = R.get(s ^ xor, 0) + 1

    ans = 1
    for k, a in L.items():
        if k not in R:
            continue
        b = R[k]
        tot = 0
        for j in range(min(a, b) + 1):
            tot += nCk(a, j) * nCk(b, j) % MOD
        ans *= tot % MOD
        ans %= MOD
    d = r - l
    ans *= pow(2, d, MOD)
    ans %= MOD
    print(ans)


for _ in range(int(input())):
    solve()