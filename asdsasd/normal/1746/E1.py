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
    n = int(input())
    A = [i for i in range(1, n + 1)]
    while len(A) >= 4:
        lst = [[] for _ in range(4)]
        for i, a in enumerate(A):
            lst[i % 4].append(a)

        A = lst[0] + lst[1]
        print("?", len(A), *A, flush=True)
        x = input()

        A = lst[0] + lst[2]
        print("?", len(A), *A, flush=True)
        y = input()

        if x == "YES":
            if y == "YES":
                A = lst[0] + lst[1] + lst[2]
            else:
                A = lst[0] + lst[1] + lst[3]
        else:
            if y == "YES":
                A = lst[0] + lst[2] + lst[3]
            else:
                A = lst[1] + lst[2] + lst[3]

    if len(A) == 3:
        a, b, c = A
        print("?", 1, a, flush=True)
        x = input()
        if x == "NO":
            print("?", 1, a, flush=True)
            x = input()
            if x == "NO":
                A = [b, c]
            else:
                print("?", 1, b, flush=True)
                x = input()
                if x == "YES":
                    A = [a, b]
                else:
                    A = [a, c]

        else:
            print("?", 1, b, flush=True)
            x = input()
            if x == "YES":
                A = [a, b]
            else:
                A = [a, c]
        

    print("!", A[0], flush=True)
    x = input()
    if x == ":)":
        return
    print("!", A[1], flush=True)
    input()

    
    

T = 1
# T = int(input())
for t in range(1, T + 1):
    solve()