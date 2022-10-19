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
    cnt = [0] * n
    ng = False
    edges = [[] for _ in range(n)]
    for _ in range(n):
        a, b = map(int, input().split())
        if a == b:
            ng = True
        a -= 1
        b -= 1
        cnt[a] += 1
        cnt[b] += 1
        edges[a].append(b)
        edges[b].append(a)
    ma = max(cnt)
    if ng or ma >= 3:
        print("NO")
        return
    bi = [-1] * n
    for i in range(n):
        if bi[i] != -1:
            continue
        bi[i] = 0
        stack = [i]
        while stack:
            pos = stack.pop()
            for npos in edges[pos]:
                if bi[npos] == -1:
                    bi[npos] = bi[pos] ^ 1
                    stack.append(npos)
                elif bi[npos] == bi[pos]:
                    print("NO")
                    return
    print("YES")
            
        



for _ in range(int(input())):
    solve()