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
MOD = 10 ** 9 + 7
bi = [1]
for _ in range(10 ** 6 + 100):
    bi.append(bi[-1] * 2 % MOD)

def solve():
    n = int(input())
    if n == 1:
        print(1)
        return
    elif n == 2:
        print(0)
        print(1)
        return
    L = [0] * n
    for i in range(n):
        if i == 0:
            L[0] = 0
        elif i == 1:
            L[1] = 2
        else:
            d = i // 2 + 1
            L[i] = bi[i + 1 - d]
    L[-1] *= 2
    L[-1] %= MOD
    R = [0] * n
    R[-1] = 2
    cum = [0] * n
    cum[-1] = 2
    for i in range(n - 2, -1, -1):
        R[i] = cum[i + 1]
        rr = 2 * i + 1
        if rr < n:
            R[i] -= cum[rr]
            R[i] %= MOD
        cum[i] = (cum[i + 1] + R[i]) % MOD
        
        
    R[-1] = 1
    ans = [l * r for l, r in zip(L, R)]
    tot = sum(ans)
    inv = pow(tot, MOD - 2, MOD)
    for i in ans:
        print(i * inv % MOD)
    
    
    
for _ in range(int(input())):
    solve()