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
    n, s = map(int, input().split())
    A = list(map(int, input().split()))
    s -= 1
    se = set(A)
    dic = {l:i for i, l in enumerate(sorted(se))}
    le = len(se)
    A = [dic[a] for a in A]
    lst = [[] for _ in range(le + 1)]
    for i, a in enumerate(A):
        lst[a + 1].append(i)
    lst[0] = [s]
    dp = [[] for _ in range(le + 1)]
    bef = [[] for _ in range(le + 1)]
    dp[0] = [0]
    inf = 1 << 30
    for ii in range(le):
        l1 = lst[ii]
        l2 = lst[ii + 1]
        le1 = len(l1)
        le2 = len(l2)
        bdp = dp[ii]
        ndp = [inf] * le2
        bef_ = [None] * le2
        if le2 == 1:
            for i in range(le1):
                tmp = abs(l1[i] - l2[0])
                tmp = min(tmp, n - tmp)
                d = bdp[i] + tmp
                if d < ndp[0]:
                    ndp[0] = d
                    bef_[0] = i
        else:
            for i in range(le1):
                for j in range(le2):
                    tmp = abs(l1[i] - l2[j])
                    tmp = min(tmp, n - tmp)
                    d = bdp[i] + tmp
                    if j == 0:
                        dd = d + l2[le2 - 1] - l2[j]
                        if dd < ndp[le2 - 1]:
                            ndp[le2 - 1] = dd
                            bef_[le2 - 1] = (i, 0)
                    else:
                        dd = d + n - (l2[j] - l2[j - 1])
                        if dd < ndp[j - 1]:
                            ndp[j - 1] = dd
                            bef_[j - 1] = (i, 0)
                    
                    if j == le2 - 1:
                        dd = d + l2[j] - l2[0]
                        if dd < ndp[0]:
                            ndp[0] = dd
                            bef_[0] = (i, 1)
                    else:
                        dd = d + n - (l2[j + 1] - l2[j])
                        if dd < ndp[j + 1]:
                            ndp[j + 1] = dd
                            bef_[j + 1] = (i, 1)

        dp[ii + 1] = ndp
        bef[ii + 1] = bef_
    min_ = 1 << 30
    t = -1
    for i, d in enumerate(dp[-1]):
        if d < min_:
            min_ = d
            t = i
    
    print(min_)
    ans = []
    for i in range(le, 0, -1):
        if type(bef[i][t]) == int:
            j = bef[i][t]
            tmp = lst[i][t] - lst[i - 1][j]
            if tmp < 0:
                tmp += n
            if tmp <= n - tmp:
                ans.append(f"+{tmp}")
            else:
                ans.append(f"-{n - tmp}")
            t = j
        else:
            j, k = bef[i][t]
            l = len(lst[i])
            if k == 1:
                r = t + 1
                if r == l:
                    r = 0
                for _ in range(l - 1):
                    d = lst[i][r] - lst[i][t]
                    if d < 0:
                        d += n
                    ans.append(f"-{d}")
                    t = r
                    r = t + 1
                    if r == l:
                        r = 0
            else:
                r = t - 1
                if r == -1:
                    r = l - 1
                for _ in range(l - 1):
                    d = lst[i][t] - lst[i][r]
                    if d < 0:
                        d += n
                    ans.append(f"+{d}")
                    t = r
                    r = t - 1
                    if r == -1:
                        r = l - 1
            
            tmp = lst[i][t] - lst[i - 1][j]
            if tmp < 0:
                tmp += n
            if tmp <= n - tmp:
                ans.append(f"+{tmp}")
            else:
                ans.append(f"-{n - tmp}")
            t = j
                    

    print(*ans[::-1], sep="\n")
    

    
for _ in range(1):
    solve()