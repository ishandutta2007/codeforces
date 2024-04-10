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

class UnionFind:
    def __init__(self, n, A):
        self.n = n
        self.parents = [-1] * n
        self.group = n
        self.A = A[:]
        self.L = [i for i in range(n)]
        self.R = [i for i in range(n)]

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
        self.L[x] = min(self.L[x], self.L[y])
        self.R[x] = max(self.R[x], self.R[y])
        self.A[x] += self.A[y]


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

def solve():
    n, k = map(int, input().split())
    A = list(map(int, input().split()))
    UF = UnionFind(n, A)

    k -= 1
    l = UF.L[UF.find(k)]
    r = UF.R[UF.find(k)]
    while l != 0 and r != n - 1:
        if UF.A[UF.find(l - 1)] >= 0:
            UF.union(l, l - 1)
            l = UF.L[UF.find(l)]
        elif UF.A[UF.find(r + 1)] >= 0:
            UF.union(r, r + 1)
            r = UF.R[UF.find(r)]
        elif UF.A[UF.find(l - 1)] + UF.A[UF.find(l)] >= 0:
            ll = UF.L[UF.find(l - 1)]
            if ll == 0:
                l = ll
                break
            UF.union(ll, ll - 1)
        elif UF.A[UF.find(r + 1)] + UF.A[UF.find(r)] >= 0:
            rr = UF.R[UF.find(r + 1)]
            if rr == n - 1:
                r = rr
                break
            UF.union(rr, rr + 1)
        else:
            print("NO")
            return

    print("YES")
    
    
for _ in range(int(input())):
    solve()