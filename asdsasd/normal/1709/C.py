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
    S = input()
    n = len(S)
    if n & 1:
        print("NO")
        return
    n //= 2
    c = n - S.count("(")
    c2 = n - S.count(")")
    if c < 0 or c2 < 0:
        print("NO")
        return
    tot = 0
    for s in S:
        if s == "?":
            if c > 0:
                s = "("
                c -= 1
            else:
                s = ")"
        if s == "(":
            tot += 1
        else:
            tot -= 1
            if tot < 0:
                print("NO")
                return
    c = n - S.count("(")
    c2 = n - S.count(")")
    if c == 0 or c2 == 0:
        print("YES")
        return
    
    tot = 0
    flg = c == 1
    for s in S:
        if s == "?":
            if c > 0 and not flg:
                s = "("
                c -= 1
                if c == 1:
                    flg = True
            else:
                flg = False
                s = ")"
        if s == "(":
            tot += 1
        else:
            tot -= 1
            if tot < 0:
                print("YES")
                return
    print("NO")

    
    
for _ in range(int(input())):
    solve()