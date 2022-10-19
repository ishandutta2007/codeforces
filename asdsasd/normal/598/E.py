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

f = lambda i, j, k: (i * 31 + j) * 51 + k
dp = [1 << 30] * (31 * 31 * 51)
for i in range(1, 31):
    for j in range(1, 31):
        if i * j <= 50:
            dp[f(i, j, i * j)] = 0
        dp[f(i, j, 0)] = 0
        for ii in range(1, i):
            for k1 in range(51):
                for k2 in range(51 - k1):
                    tmp = dp[f(ii, j, k1)] + dp[f(i - ii, j, k2)] + j ** 2
                    dp[f(i, j, k1 + k2)] = min(dp[f(i, j, k1 + k2)], tmp)
        for jj in range(1, j):
            for k1 in range(51):
                for k2 in range(51 - k1):
                    tmp = dp[f(i, jj, k1)] + dp[f(i, j - jj, k2)] + i ** 2
                    dp[f(i, j, k1 + k2)] = min(dp[f(i, j, k1 + k2)], tmp)


def solve():
    n, m, k = map(int, input().split())
    print(dp[f(n, m, k)])
    

for _ in range(int(input())):
    solve()