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
    h, w = map(int, input().split())
    S = [input() for _ in range(h)]
    used = [[False] * w for _ in range(h)]

    ok = {(1, 0, 1, 1), (1, -1, 1, 0), (0, 1, 1, 1), (0, 1, 1, 0)}
    for i in range(h):
        for j in range(w):
            if used[i][j]:
                continue
            if S[i][j] == ".":
                continue
            stack = [(i, j)]
            point = [(i, j)]
            used[i][j] = True
            while stack:
                x, y = stack.pop()
                for dx in range(-1, 2):
                    for dy in range(-1, 2):
                        ni = x + dx
                        nj = y + dy
                        if ni == -1 or ni == h or nj == -1 or nj == w:
                            continue
                        if used[ni][nj] or S[ni][nj] == ".":
                            continue
                        used[ni][nj] = True
                        stack.append((ni, nj))
                        point.append((ni, nj))
            if len(point) != 3:
                print("No")
                return

            point.sort(key = lambda x:(x[0], x[1]))
            di1 = point[1][0] - point[0][0]
            dj1 = point[1][1] - point[0][1]
            di2 = point[2][0] - point[0][0]
            dj2 = point[2][1] - point[0][1]
            if (di1, dj1, di2, dj2) not in ok:
                print("No")
                return
            

    print("Yes")




for _ in range(int(input())):
    solve()