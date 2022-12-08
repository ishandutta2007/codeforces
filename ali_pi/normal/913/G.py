import sys
import math
from decimal import *
line = lambda: list(int(x) for x in raw_input().split())
def pow(a, k, p):
    r = 1
    t = a
    while k > 0:
        if k % 2 == 1:
            r = r * t % p
        t = t * t % p
        k >>= 1
    return r
test = input()
for i in range(0, test):
    x = input()
    x = x * 10 ** 6
    x += (2 ** 17 - x % 2 ** 17) % 2 ** 17
    if x % 5 == 0:
        x += 2 ** 17;
    res = 0
    for i in range(1, 17 + 1):
        while pow(2, res, 5 ** i) != x % 5 ** i:
            if i == 1:
                res += 1
            else:
                res += 4 * 5 ** (i - 2)
    res += 4 * 5 ** 16
    print(res)