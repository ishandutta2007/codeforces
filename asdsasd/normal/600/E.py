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
from collections import deque

def solve():
    n = int(input())
    C = list(map(int, input().split()))
    edges = [[] for _ in range(n)]
    for _ in range(n - 1):
        u, v = map(int, input().split())
        u -= 1
        v -= 1
        edges[u].append(v)
        edges[v].append(u)
    queue = deque()
    queue.append(0)
    dist = [-1] * n
    dist[0] = 0
    route = [0]
    while queue:
        pos = queue.popleft()
        for npos in edges[pos]:
            if dist[npos] != -1:
                continue
            dist[npos] = dist[pos] + 1
            queue.append(npos)
            route.append(npos)
    dp = [{} for _ in range(n)]
    used = [False] * n
    ans = [0] * n
    ans_ = [0] * n
    ma_cnt = [0] * n
    for pos in route[::-1]:
        used[pos] = True
        dp[pos][C[pos]] = 1
        ans[pos] = C[pos]
        ma_cnt[pos] = 1
        for npos in edges[pos]:
            if not used[npos]:
                continue
            if len(dp[pos]) < len(dp[npos]):
                dp[pos], dp[npos] = dp[npos], dp[pos]
                ans[pos], ans[npos] = ans[npos], ans[pos]
                ma_cnt[pos], ma_cnt[npos] = ma_cnt[npos], ma_cnt[pos]
            for k, v in dp[npos].items():
                dp[pos][k] = dp[pos].get(k, 0) + v
                if ma_cnt[pos] < dp[pos][k]:
                    ma_cnt[pos] = dp[pos][k]
                    ans[pos] = k
                elif ma_cnt[pos] == dp[pos][k]:
                    ans[pos] += k

        ans_[pos] = ans[pos]
    print(*ans_)

        

for _ in range(1):
    solve()