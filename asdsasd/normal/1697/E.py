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

import random
MOD = 998244353
N = 200
fact = [0 for _ in range(N)]
invfact = [0 for _ in range(N)]
fact[0] = 1
for i in range(1, N):
    fact[i] = fact[i - 1] * i % MOD

invfact[N - 1] = pow(fact[N - 1], MOD - 2, MOD)

for i in range(N - 2, -1, -1):
    invfact[i] = invfact[i + 1] * (i + 1) % MOD

def nCk(n, k):
    if k < 0 or n < k:
        return 0
    else:
        return (fact[n] * invfact[k] % MOD) * invfact[n - k] % MOD

def nHk(n, k):
    return nCk(n + k - 1, k)




def solve():
    n = int(input())
    xy = [list(map(int, input().split())) for _ in range(n)]
    dist = [[0] * n for _ in range(n)]
    for i in range(n):
        for j in range(i + 1, n):
            dx = xy[i][0] - xy[j][0]
            dy = xy[i][1] - xy[j][1]
            d = abs(dx) + abs(dy)
            dist[i][j] = d
            dist[j][i] = d
    min_se = [set() for _ in range(n)]
    hash_ = [random.randrange(1, 1 << 63) for _ in range(n)]
    min_hash = [0 for _ in range(n)]
    cnt = [0] * n
    for i in range(n):
        min_ = 1 << 30
        for j in range(n):
            if i != j:
                min_ = min(min_, dist[i][j])
        for j in range(n):
            if dist[i][j] == min_:
                min_se[i].add(j)
                min_hash[i] ^= hash_[j]
                cnt[i] += 1
    
    two = 0
    for i in range(n):
        if cnt[i] != 1:
            continue
        ok = True
        se = {min_hash[i] ^ hash_[i]}
        for j in min_se[i]:
            if j < i:
                ok = False
                break
            se.add(min_hash[j] ^ hash_[j])
        if ok and len(se) == 1:
            two += 1

    three = 0
    for i in range(n):
        if cnt[i] != 2:
            continue
        ok = True
        se = {min_hash[i] ^ hash_[i]}
        for j in min_se[i]:
            if j < i:
                ok = False
                break
            se.add(min_hash[j] ^ hash_[j])
        if ok and len(se) == 1:
            three += 1

    four = 0
    for i in range(n):
        if cnt[i] != 3:
            continue
        ok = True
        se = {min_hash[i] ^ hash_[i]}
        for j in min_se[i]:
            if j < i:
                ok = False
                break
            se.add(min_hash[j] ^ hash_[j])
        if ok and len(se) == 1:
            four += 1
    
    ans = 0
    for a in range(two + 1):
        for b in range(three + 1):
            for c in range(four + 1):
                x = n - a - 2 * b - 3 * c
                tmp = nCk(n, x) * fact[x] % MOD
                tmp *= nCk(two, a) * nCk(three, b) * nCk(four, c) % MOD
                ans += tmp % MOD
                ans %= MOD
    print(ans)

    


    
for _ in range(1):
    solve()