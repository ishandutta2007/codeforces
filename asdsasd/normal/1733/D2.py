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
    n, x, y = map(int, input().split())
    x = min(x, 2 * y)
    lst = []
    S = input()
    T = input()
    for i in range(n):
        if S[i] != T[i]:
            lst.append(i)
    if len(lst) & 1:
        print(-1)
        return
    elif not lst:
        print(0)
        return

    le = len(lst)    
    if le == 2:
        d = lst[1] - lst[0]
        if d == 1:
            print(x)
        else:
            ans = min(y, d * x)
            print(ans)
        return

    a = (le // 2) * y
    b = 1 << 60
    bi = lst[0]
    for i in lst[1:]:
        d = i - bi
        if d == 1:
            c = x
        else:
            c = min(y, d * x)
        nb = a + c - y
        na = min(a, b)
        a = na
        b = nb
        bi = i
    print(min(a, b))
    
    
for _ in range(int(input())):
    solve()