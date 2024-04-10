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
MOD = 10 ** 9  + 7

def solve():
    n = int(input())
    A = list(map(int, input().split()))
    dp = [-1 << 30] * (n + 1)
    dp[0] = 0
    for l in range(0, 1):
        max_ = 0
        cnt = {}
        d = 0
        for r in range(l, n):
            if not d & 1 and 2 * max_ <= d:
                dp[r + 1] = max(dp[r + 1], dp[l] + 1)
            a = A[r]
            cnt[a] = cnt.get(a, 0) + 1
            max_ = max(max_, cnt[a])
            d += 1
        if not d & 1 and 2 * max_ <= d:
            dp[n] = max(dp[n], dp[l])
    for l in range(1, n):
        max_ = 0
        cnt = {}
        d = 0
        for r in range(l, n):
            if not d & 1 and 2 * max_ <= d and A[l - 1] == A[r]:
                dp[r + 1] = max(dp[r + 1], dp[l] + 1)
            a = A[r]
            cnt[a] = cnt.get(a, 0) + 1
            max_ = max(max_, cnt[a])
            d += 1
        if not d & 1 and 2 * max_ <= d:
            dp[n] = max(dp[n], dp[l])
    
    print(dp[-1])
    
    



for _ in range(int(input())):
    solve()