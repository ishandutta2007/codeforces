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

class SegTree:
    def __init__(self, n, e, ope, lst=[]):
        self.N0 = 2 ** (n - 1).bit_length()
        self.e = e
        self.ope = ope
        self.data = [e] * (2 * self.N0)
        if lst:
            for i in range(n):
                self.data[self.N0 + i] = lst[i]
            for i in range(self.N0 - 1, 0, -1):
                self.data[i] = self.ope(self.data[2 * i], self.data[2 * i + 1])
    
    def build(self):
        for i in range(self.N0 - 1, 0, -1):
            self.data[i] = self.ope(self.data[2 * i], self.data[2 * i + 1])
                
    def update(self, i, x): #a_ix
        i += self.N0
        self.data[i] = x
        while i > 1:
            i >>= 1
            self.data[i] = self.ope(self.data[2 * i], self.data[2 * i + 1])
    
    def add(self, i, x):
        self.update(i, x + self.get(i))

    def set(self, i, x):
        self.data[self.N0 + i] = x
    
    def query(self, l, r): #[l, r)
        if r <= l:
            return self.e
        lres = self.e
        rres = self.e
        l += self.N0
        r += self.N0
        while l < r:
            if l & 1:
                lres = self.ope(lres, self.data[l])
                l += 1
            if r & 1:
                r -= 1
                rres = self.ope(self.data[r], rres)
            l >>= 1
            r >>= 1
        return self.ope(lres, rres)
    
    def get(self, i): #a_i
        return self.data[self.N0 + i]

def solve():
    n, m = map(int, input().split())
    A = list(map(int, input().split()))
    A = [n - a for a in A]
    q = int(input())
    seg = SegTree(m, 1 << 30, min, A)
    for _ in range(q):
        ys, xs, yf, xf, k = map(int, input().split())
        xs -= 1
        xf -= 1
        ys = n + 1 - ys
        yf = n + 1 - yf
        if xs > xf:
            xs, xf = xf, xs
            ys, yf = yf, ys
        if (xf - xs) % k != 0:
            print("NO")
            continue
        elif abs(yf - ys) % k != 0:
            print("NO")
            continue
        y = (yf - 1) % k + 1
        mi = seg.query(xs, xf + 1)
        if y <= mi:
            print("YES")
        else:
            print("NO")

        


    
    
for _ in range(1):
    solve()