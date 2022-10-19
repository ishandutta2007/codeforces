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
    A = [list(map(int, input())) for _ in range(n)]
    mi = n // 2
    mj = (n + 1) // 2
    one = [[0] * mj for _ in range(mi)]
    zero = [[0] * mj for _ in range(mi)]
    for _ in range(4):
        for i in range(mi):
            for j in range(mj):
                if A[i][j] == 1:
                    one[i][j] += 1
                else:
                    zero[i][j] += 1
        B = [[0] * n for _ in range(n)]
        for i in range(n):
            for j in range(n):
                B[j][n - 1 - i] = A[i][j]
        A = [row[:] for row in B]
    ans = 0
    for i in range(mi):
        for j in range(mj):
            ans += min(one[i][j], zero[i][j])
    print(ans)

    
    
for _ in range(int(input())):
    solve()