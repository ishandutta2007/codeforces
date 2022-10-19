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

from pprint import pprint

DEBUG = False

if DEBUG:
    n = 7
    A = [6, 3, 2, 7, 5, 1, 4]
    x = "1"
    def print(Q, flush):
        pprint(Q)
        if Q[0] == "!":
            i = int(Q[2:])
            assert A[i - 1] == i
            return
        l, r = map(int, Q.split()[1:])
        B = sorted(A[l-1:r])
        global x
        x = " ".join(map(str, B))
        
    def input():
        return x

def judge(Q):
    print(Q, flush = True)
    if Q[0] == "!":
        return
    return list(map(int, input().split()))


def solve():
    if DEBUG:
        global n
    else:
        n = int(input())
    l = 0
    r = n
    while r - l > 1:
        mid = (l + r) // 2
        A = judge(f"? {1} {mid}")
        cnt = sum(a <= mid for a in A)
        if cnt & 1:
            r = mid
        else:
            l = mid

    judge(f"! {r}")
    
for _ in range(int(input())):
    solve()