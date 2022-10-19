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
from math import gcd

def Z_algorithm(S):
    l = len(S)
    Z = [0] * l
    Z[0] = l
    i = 1
    j = 0
    while i < l:
        while i + j < l and S[j] == S[i + j]: j += 1
        Z[i] = j
        if j == 0:
            i += 1
            continue
        k = 1
        while i + k < l and k + Z[k] < j:
            Z[i + k] = Z[k]
            k += 1
        i += k
        j -= k
    return Z

def solve():
    n = int(input())
    S = input()
    P = list(map(int, input().split()))
    P = [p - 1 for p in P]
    used = [False] * n
    ans = 1
    for i in range(n):
        if used[i]:
            continue
        used[i] = True
        T = [S[i]]
        while not used[P[i]]:
            i = P[i]
            used[i] = True
            T.append(S[i])
        le = len(T)
        T += T
        Z = Z_algorithm(T)
        x = 1
        while 1:
            if Z[x] >= le:
                break
            x += 1
        ans = ans * x // gcd(ans, x)
    print(ans)




    
    
for _ in range(int(input())):
    solve()