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
    n, m = map(int, input().split())
    points = [tuple(map(float, input().split())) for _ in range(n)]
    def sign(x):
        if x == 0:
            return x
        elif x > 0:
            return 1
        else:
            return -1
    for _ in range(m):
        x0, y0, x1, y1 = map(float, input().split())
        dx = x1 - x0
        dy = y1 - y0
        d = (dx * dx + dy * dy) ** 0.5
        lst = []
        for i in range(n):
            x2, y2 = points[i - 1]
            x3, y3 = points[i]
            t1x = (x2 - x0) * dx + (y2 - y0) * dy
            t1y = (y2 - y0) * dx - (x2 - x0) * dy

            t2x = (x3 - x0) * dx + (y3 - y0) * dy
            t2y = (y3 - y0) * dx - (x3 - x0) * dy

            if sign(t1y) != sign(t2y):
                lst.append(((t2x * t1y - t1x * t2y) / (t1y - t2y), sign(t2y) - sign(t1y)))
        lst.sort()

        ans = 0
        tot = 0
        for i in range(1, len(lst)):
            tot += lst[i - 1][1]
            if tot != 0:
                ans += lst[i][0] - lst[i - 1][0]
        print(ans / d)


    

for _ in range(1):
    solve()