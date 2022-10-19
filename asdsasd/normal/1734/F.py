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
    n, m = map(int, input().split())
    d = 62
    dp = [0] * 8
    def f(car, lt, even):
        return 4 * car + 2 * lt + even

    dp[f(0, 1, 0)] = 1
    
    for _ in range(d):
        s = n & 1
        t = m & 1
        n >>= 1
        m >>= 1
        ndp = [0] * 8
        for car in range(2):
            for lt in range(2):
                for even in range(2):
                    if car:
                        ss = s + 1
                    else:
                        ss = s
                    
                    for x in range(2):
                        if x < t:
                            j = 0
                        elif x > t:
                            j = 1
                        else:
                            j = lt

                        if ss + x >= 2:
                            i = 1
                        else:
                            i = 0

                        if (ss + x) & 1 == x:
                            k = even
                        else:
                            k = even ^ 1

                        ndp[f(i, j, k)] += dp[f(car, lt, even)]
        dp = ndp
    ans = dp[f(0, 0, 1)]
    print(ans)

                    





    
for _ in range(int(input())):
    solve()