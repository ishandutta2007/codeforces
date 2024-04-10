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
    n, K = map(int, input().split())
    S = [list(input()) for _ in range(n)]
    A = [[] for _ in range(n)]    
    for i in range(n - 1, -1, -1):
        for j in range(n):
            if S[i][j] == "0":
                A[j].append(i)            

    used = [[False] * n for _ in range(n)]
    add = n - K + 2
    cc = 0
    for j in range(K - 1): 
        x = n - 1
        for i in range(j, j + add):
            if not A[i] or A[i][-1] > x:
                nx = x
            else:
                nx = A[i][-1]
                while A[i] and A[i][-1] <= x:
                    A[i].pop()
            nx = min(nx, n - 1 - (K - 2 - j))
            if i == j + add - 1:
                nx = 0
            
            for k in range(nx, x + 1):
                if used[k][i]:
                    print("NO")
                    return
                used[k][i] = True
                cc += 1
            x = nx

    
    for i in range(n):
        if A[i]:
            print("NO")
            return

    ans = [[1] * n for _ in range(n)]
    c = (n - K + 1) ** 2
    assert c + cc == n ** 2
    for i in range(n):
        for j in range(n):
            if used[i][j]:
                continue
            if S[i][j] == "1":
                c -= 1
                ans[i][j] = 0
            else:
                print("NO")
                return
            
    if c != 0:
        print("NO")
    else:
        print("YES")
        for row in ans:
            print(*row, sep="")




for _ in range(int(input())):
    solve()