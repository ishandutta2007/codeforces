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

class FFT:
    def __init__(self, MOD=998244353):
        FFT.MOD = MOD
        g = self.primitive_root_constexpr()
        ig = pow(g, FFT.MOD - 2, FFT.MOD)
        FFT.W = [pow(g, (FFT.MOD - 1) >> i, FFT.MOD) for i in range(30)]
        FFT.iW = [pow(ig, (FFT.MOD - 1) >> i, FFT.MOD) for i in range(30)]

    def primitive_root_constexpr(self):
        if FFT.MOD == 998244353:
            return 3
        elif FFT.MOD == 200003:
            return 2
        elif FFT.MOD == 167772161:
            return 3
        elif FFT.MOD == 469762049:
            return 3
        elif FFT.MOD == 754974721:
            return 11
        divs = [0] * 20
        divs[0] = 2
        cnt = 1
        x = (FFT.MOD - 1) // 2
        while x % 2 == 0:
            x //= 2
        i = 3
        while i * i <= x:
            if x % i == 0:
                divs[cnt] = i
                cnt += 1
                while x % i == 0:
                    x //= i
            i += 2
        if x > 1:
            divs[cnt] = x
            cnt += 1
        g = 2
        while 1:
            ok = True
            for i in range(cnt):
                if pow(g, (FFT.MOD - 1) // divs[i], FFT.MOD) == 1:
                    ok = False
                    break
            if ok:
                return g
            g += 1

    def fft(self, k, f):
        for l in range(k, 0, -1):
            d = 1 << l - 1
            U = [1]
            for i in range(d):
                U.append(U[-1] * FFT.W[l] % FFT.MOD)
            
            for i in range(1 << k - l):
                for j in range(d):
                    s = i * 2 * d + j
                    f[s], f[s + d] = (f[s] + f[s + d]) % FFT.MOD, U[j] * (f[s] - f[s + d]) % FFT.MOD

    def ifft(self, k, f):
        for l in range(1, k + 1):
            d = 1 << l - 1
            for i in range(1 << k - l):
                u = 1
                for j in range(i * 2 * d, (i * 2 + 1) * d):
                    f[j+d] *= u
                    f[j], f[j + d] = (f[j] + f[j + d]) % FFT.MOD, (f[j] - f[j + d]) % FFT.MOD
                    u = u * FFT.iW[l] % FFT.MOD

    def convolve(self, A, B):
        n0 = len(A) + len(B) - 1
        k = (n0).bit_length()
        n = 1 << k
        A += [0] * (n - len(A))
        B += [0] * (n - len(B))
        self.fft(k, A)
        self.fft(k, B)
        A = [a * b % FFT.MOD for a, b in zip(A, B)]
        self.ifft(k, A)
        inv = pow(n, FFT.MOD - 2, FFT.MOD)
        A = [a * inv % FFT.MOD for a in A]
        del A[n0:]
        return A

MOD = 998244353
def solve():
    n, k, f = map(int, input().split())
    if f > 2 * k:
        print(0)
        return

    fft = FFT()
    A = [1] * (k + 1)
    for i in range(n):
        B = fft.convolve(A[:], A[:])
        if i == n - 1:
            break
        tot = sum(B[k+1:]) % MOD
        A = [0] * (k + 1)
        cum = 0
        for i in range(k, -1, -1):
            A[i] += tot + B[i] * (k + 1 - i)
            A[i] %= MOD
            tot += B[i]
            if tot >= 0:
                tot -= MOD
    print(B[f])
    
    
for _ in range(1):
    solve()