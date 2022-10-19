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

import random


def solve():
    n = int(input())
    A = list(map(int, input().split()))
    x = random.randrange(1 << 63)
    ans = (A[0], 1, 1)
    A = [a ^ x for a in A]
    lst = {}
    for i, a in enumerate(A):
        if a not in lst:
            lst[a] = []
        lst[a].append(i)
    max_ = -1 << 30
    for k, ls in lst.items():
        B = [2 * i - l for i, l in enumerate(ls)]
        mi = 1 << 40
        mind = -1
        for i, a in enumerate(B):
            if a < mi:
                mi = a
                mind = i
            if a - mi > max_:
                max_ = a - mi
                ans = (k ^ x, ls[mind] + 1, ls[i] + 1)

        
    print(*ans)
    return
    k = x ^ ans[0]
    tot = 0
    for i in range(ans[1] - 1, ans[2]):
        if A[i] == k:
            tot += 1
        else:
            tot -= 1
    print(tot)

    
for _ in range(int(input())):
    solve()