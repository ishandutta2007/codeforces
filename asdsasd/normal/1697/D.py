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
    bef = 0
    ans = [""] * n
    for i in range(n):
        print("?", 2, 1, i + 1, flush=True)
        x = int(input())
        if x == bef + 1:
            print("?", 1, i + 1, flush=True)
            ans[i] = input()
        bef = x

    last = [-1] * 26
    for i in range(n):
        if ans[i] != "":
            p = ord(ans[i]) - 97
            last[p] = i + 1
            continue
        lst = [l for l in last if l != -1]
        lst.sort()
        le = len(lst)
        r = le
        l = 0
        while r - l > 1:
            mid = (l + r) // 2
            print("?", 2, lst[mid], i + 1, flush=True)
            x = int(input())
            if x == le - mid:
                l = mid
            else:
                r = mid
        ans[i] = ans[lst[l] - 1]
        p = ord(ans[i]) - 97
        last[p] = i + 1
    print("!", "".join(ans), flush=True)

    

    
for _ in range(1):
    solve()