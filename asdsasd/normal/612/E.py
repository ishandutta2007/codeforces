import os
from re import M
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
    P = list(map(int, input().split()))
    P = [p - 1 for p in P]
    Q = [-1] * n
    size = {}
    used = [False] * n
    for i in range(n):
        if used[i]:
            continue
        lst = []
        while not used[i]:
            used[i] = True
            lst.append(i)
            i = P[i]
        le = len(lst)
        if le & 1:
            c = (le + 1) // 2
            for i in range(le):
                Q[lst[i]] = lst[(i + c) % le]
        elif le not in size:
            size[le] = lst
        else:
            lst2 = size[le]
            del size[le]
            lst.append(lst[0])
            for i in range(le):
                Q[lst[i]] = lst2[i]
                Q[lst2[i]] = lst[i + 1]
    if -1 in Q:
        print(-1)
    else:
        Q = [q + 1 for q in Q]
        print(*Q)

        




    
for _ in range(1):
    solve()