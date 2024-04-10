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

class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y
        
    def area(self):
        if self.y < 0:
            if self.x < 0:
                return 1
            else:
                return 2
        else:
            if self.x >= 0:
                return 3
            else:
                return 4
        
    def __lt__(self, other):
        ap = self.area()
        aq = other.area()
        if ap < aq:
            return True
        elif ap > aq:
            return False
        else:
            return self.x * other.y > other.x * self.y

def solve():
    n = int(input())
    points = []
    for i in range(1, n + 1):
        x, y = map(int, input().split())
        points.append((Point(x, y), i))
    points.sort()
    points.append(points[0])
    nume = -2
    deno = 1
    for i in range(n):
        x0, y0 = points[i][0].x, points[i][0].y
        x1, y1 = points[i + 1][0].x, points[i + 1][0].y
        ab = x0 * x1 + y0 * y1
        d1 = x0 ** 2 + y0 ** 2
        d2 = x1 ** 2 + y1 ** 2
        if ab < 0:
            ab **= 2
            ab *= -1
        else:
            ab **= 2
        dd = d1 * d2
        if ab * deno > dd * nume:
            deno, nume = dd, ab
            ans = (points[i][1], points[i + 1][1])
    print(*ans)

        
    
for _ in range(1):
    solve()