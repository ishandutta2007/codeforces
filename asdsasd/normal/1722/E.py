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
    n, q = map(int, input().split())
    N = 1001
    dp = [[0] * N for _ in range(N)]
    for _ in range(n):
        h, w = map(int, input().split())
        dp[h][w] += h * w
    for i in range(N):
        for j in range(N):
            if i == 0 and j == 0:
                pass
            elif i == 0:
                dp[i][j] += dp[i][j - 1]
            elif j == 0:
                dp[i][j] += dp[i - 1][j]
            else:
                dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1]
    
    for _ in range(q):
        h1, w1, h2, w2 = map(int, input().split())
        h2 -= 1
        w2 -= 1
        ans = dp[h2][w2] - dp[h1][w2] - dp[h2][w1] + dp[h1][w1]
        print(ans)


for _ in range(int(input())):
    solve()