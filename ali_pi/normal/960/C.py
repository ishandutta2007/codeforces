from math import *
R = lambda: map(int,input().split())
x, d = R()
n = 0; arr = []; v = 1
while x:
    t = floor(log2(x+1))
    arr += [v] * t
    n += t; v += d
    x -= (2**t) - 1
print(n)
print(' '.join(map(str, arr)))