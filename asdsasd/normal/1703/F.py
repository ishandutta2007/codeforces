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

class Bit:
    def __init__(self, n):
        self.size = n
        self.n0 = 1 << (n.bit_length() - 1)
        self.tree = [0] * (n + 1)
    
    def range_sum(self, l, r):
        return self.sum(r - 1) - self.sum(l - 1)
        
    def sum(self, i):
        i += 1
        s = 0
        while i > 0:
            s += self.tree[i]
            i -= i & -i
        return s
        
    def get(self, i):
        return self.sum(i) - self.sum(i - 1)
 
    def add(self, i, x):
        i += 1
        while i <= self.size:
            self.tree[i] += x
            i += i & -i
         
    def lower_bound(self, x):
        pos = 0
        plus = self.n0
        while plus > 0:
            if pos + plus <= self.size and self.tree[pos + plus] < x:
                x -= self.tree[pos + plus]
                pos += plus
            plus //= 2
        return pos


def solve():
    n = int(input())
    A = list(map(int, input().split()))
    bit = Bit(n + 10)
    ans = 0
    for i, a in enumerate(A, 1):
        if a >= i:
            continue
        ans += bit.sum(a)
        bit.add(i + 1, 1)
    print(ans)

    
    
for _ in range(int(input())):
    solve()